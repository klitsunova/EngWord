#include "main_window.h"

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent),
                                              stacked_widgets_(new QStackedWidget(this)),
                                              menu_(new Menu(this)) {
  setMinimumSize(main_window_sizes::kScreenSizeDefault);
  setWindowTitle("Duolingo");
  setWindowIcon(QIcon("../resources/images/MainWindow/icon.svg"));
  SetWidgets();
  ConnectUI();

}

void MainWindow::SetWidgets() {
  stacked_widgets_->addWidget(menu_);
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
}
