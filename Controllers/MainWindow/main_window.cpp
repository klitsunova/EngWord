#include "main_window.h"

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent),
                                              stacked_widgets_(new QStackedWidget(this)),
                                              menu_(new Menu(this)),
                                              settings_view_(new SettingsView(this)),
                                              keyEsc_(new QShortcut(Qt::Key_Escape, this, SLOT(close()))) {
  setMinimumSize(main_window_sizes::kScreenSizeDefault);
  setWindowTitle("Duolingo");
  setWindowIcon(QIcon("../resources/images/MainWindow/icon.svg"));
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
          &MainWindow::HideSettings);
}

void MainWindow::resizeEvent(QResizeEvent*) {
  stacked_widgets_->setGeometry(0, 0, width(), height());
  setAutoFillBackground(true);
  QBrush brush;
  QPalette palette;
  brush.setTextureImage(QImage("../resources/images/MainWindow/background.svg"));
  palette.setBrush(QPalette::Window, brush);
  setPalette(palette);
}

void MainWindow::PickModStarted() {
}

void MainWindow::InputModStarted() {
}

void MainWindow::AudioModStarted() {
}

void MainWindow::MixedModStarted() {
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
