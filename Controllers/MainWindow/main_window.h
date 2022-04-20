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

#include "Controllers/exercises_controller.h"
#include "Controllers/settings.h"

#include "Views/Menu/menu.h"
#include "Views/Menu/settings_view.h"

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

  void ReturnToMenu();

  void SaveSettings();
  void RestoreSettings();

  void closeEvent(QCloseEvent* event) override;

  QStackedWidget* stacked_widgets_ = nullptr;
  Menu* menu_ = nullptr;
  SettingsView* settings_view_ = nullptr;

  ExercisesController* controller_ = nullptr;

  QShortcut* keyEsc_;
};
