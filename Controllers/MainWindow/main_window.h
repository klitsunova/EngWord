#pragma once

#include <QBrush>
#include <QCloseEvent>
#include <QColor>
#include <QCoreApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>
#include <QSettings>
#include <QShortcut>
#include <QStackedWidget>

#include "helpers/backgrounds.h"
#include "helpers/sizes.h"

#include "Controllers/settings.h"

#include "Views/menu.h"
#include "Views/settings_view.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QMainWindow* parent = nullptr);
  ~MainWindow() override = default;

 private:
  void SetWidgets();
  void ConnectUI();

  void resizeEvent(QResizeEvent*) override;

  void PickModStarted();
  void InputModStarted();
  void AudioModStarted();
  void MixedModStarted();
  void ShowSettings();
  void HideSettings();
  bool checkExit();

  //void StartExercise();
  //void ReturnToMainWindow();

  void SaveSettings();

  void closeEvent(QCloseEvent* event) override;

  QStackedWidget* stacked_widgets_ = nullptr;
  Menu* menu_ = nullptr;
  SettingsView* settings_view_ = nullptr;

  //EventsController* events_controller_ = nullptr;

  QShortcut* keyEsc_;
};
