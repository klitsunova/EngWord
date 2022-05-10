#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QStackedWidget>

#include "Controllers/exercises_controller.h"
#include "Views/Menu/menu.h"
#include "Views/Menu/settings_view.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QMainWindow* parent = nullptr);
  ~MainWindow() override = default;

  void resizeEvent(QResizeEvent*) override;
  void closeEvent(QCloseEvent* event) override;

 private:
  void SetWidgets();

  void ConnectUI();

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

  void CreateController();

  QStackedWidget* stacked_widgets_ = nullptr;
  Menu* menu_ = nullptr;
  SettingsView* settings_view_ = nullptr;
  ExercisesController* controller_ = nullptr;
  QShortcut* keyEsc_;
};
