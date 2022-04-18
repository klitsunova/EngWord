#pragma once

#include <QBrush>
#include <QCloseEvent>
#include <QColor>
#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>
#include <QSettings>
#include <QShortcut>
#include <QStackedWidget>

#include "helpers/backgrounds.h"
#include "helpers/sizes.h"

#include "Views/menu.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QMainWindow* parent = nullptr);
  ~MainWindow() override = default;

 private:
  void resizeEvent(QResizeEvent*) override;

  void SetWidgets();
  void ConnectUI();
  //void ConnectController();

  void PickModStarted();
  void InputModStarted();
  void AudioModStarted();
  void MixedModStarted();

  //void StartExercise();
  //void ReturnToMainWindow();

  void ReadSettings();
  void ShowSettings();
  void WriteSettings();
  //void HideSettings();

  bool checkExit();
  void closeEvent(QCloseEvent* event) override;

  QStackedWidget* stacked_widgets_ = nullptr;
  Menu* menu_ = nullptr;
  QSettings game_settings = QSettings("Klitsunova", "Duolingo");
  //EventsController* events_controller_ = nullptr;

  QShortcut* keyEsc_;
};
