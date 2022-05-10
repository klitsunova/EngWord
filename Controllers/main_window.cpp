#include "main_window.h"

#include <QBrush>
#include <QCloseEvent>
#include <QColor>
#include <QCoreApplication>
#include <QMessageBox>
#include <QPalette>
#include <QSettings>

#include "Models/settings.h"
#include "helpers/backgrounds.h"
#include "helpers/sizes.h"

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent),
                                              stacked_widgets_(new QStackedWidget(this)),
                                              menu_(new Menu(this)),
                                              settings_view_(new SettingsView(this)),
                                              keyEsc_(new QShortcut(Qt::Key_Escape, this, SLOT(close()))) {
  setMinimumSize(window_sizes::kScreenSizeDefault);
  setWindowTitle("Duolingo");
  setWindowIcon(QIcon(":/images/MainWindow/icon.svg"));
  menu_->SetScoreLabel(Settings::GetScoreString());
  SetWidgets();
  ConnectUI();
}

void MainWindow::SetWidgets() {
  stacked_widgets_->addWidget(menu_);
  stacked_widgets_->addWidget(settings_view_);
  stacked_widgets_->setCurrentWidget(menu_);
}

void MainWindow::ConnectUI() {
  connect(menu_,
          &Menu::PickModButtonPressed,
          this,
          &MainWindow::PickModStarted);
  connect(menu_,
          &Menu::InputModButtonPressed,
          this,
          &MainWindow::InputModStarted);
  connect(menu_,
          &Menu::AudioModButtonPressed,
          this,
          &MainWindow::AudioModStarted);
  connect(menu_,
          &Menu::MixedModButtonPressed,
          this,
          &MainWindow::MixedModStarted);
  connect(menu_,
          &Menu::SettingsButtonPressed,
          this,
          &MainWindow::ShowSettings);
  connect(menu_,
          &Menu::ExitButtonPressed,
          this,
          &MainWindow::close);
  connect(settings_view_,
          &SettingsView::ApplyChanges,
          this,
          &MainWindow::SaveSettings);
  connect(settings_view_,
          &SettingsView::CloseSettings,
          this,
          &MainWindow::RestoreSettings);
}

void MainWindow::resizeEvent(QResizeEvent*) {
  stacked_widgets_->setGeometry(0, 0, width(), height());
  setAutoFillBackground(true);
  QBrush brush;
  QPalette palette;
  brush.setTextureImage(QImage(":/images/MainWindow/background.svg"));
  palette.setBrush(QPalette::Window, brush);
  setPalette(palette);
}

void MainWindow::PickModStarted() {
  CreateController();
  controller_->StartExerciseSet(Mode::kPick);
  hide();
}

void MainWindow::InputModStarted() {
  CreateController();
  controller_->StartExerciseSet(Mode::kInput);
  hide();
}

void MainWindow::AudioModStarted() {
  CreateController();
  controller_->StartExerciseSet(Mode::kAudio);
  hide();
}

void MainWindow::MixedModStarted() {
  CreateController();
  controller_->StartExerciseSet(Mode::kMixed);
  hide();
}

void MainWindow::ShowSettings() {
  stacked_widgets_->setCurrentWidget(settings_view_);
}

void MainWindow::HideSettings() {
  stacked_widgets_->setCurrentWidget(menu_);
}

bool MainWindow::checkExit() {
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(
      this,
      "Exit",
      "Are you sure you want to exit?",
      QMessageBox::No | QMessageBox::Yes);
  if (reply == QMessageBox::Yes) {
    return true;
  }
  return false;
}

void MainWindow::closeEvent(QCloseEvent* event) {
  if (checkExit()) {
    event->accept();
  } else {
    event->ignore();
  }
}

void MainWindow::SaveSettings() {
  Settings::SetSettings(
      settings_view_->GetLevelSettings(),
      settings_view_->GetSoundSettings(),
      settings_view_->GetScoreSettings());
  HideSettings();
}

void MainWindow::RestoreSettings() {
  settings_view_->GetSettingsView();
  HideSettings();
}

void MainWindow::ReturnToMenu() {
  controller_->CloseView();
  menu_->SetScoreLabel(Settings::GetScoreString());
  show();
}

void MainWindow::CreateController() {
  delete controller_;
  controller_ = new ExercisesController();
  connect(controller_,
          &ExercisesController::Back,
          this,
          &MainWindow::ReturnToMenu);
}
