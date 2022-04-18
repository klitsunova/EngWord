#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QPalette>
#include <QColor>
#include <QBrush>

#include "helpers/sizes.h"
#include "helpers/backgrounds.h"
#include "menu.h"

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

  void ShowSettings();
  //void HideSettings();

  QStackedWidget* stacked_widgets_ = nullptr;
  Menu* menu_ = nullptr;
  //EventsController* events_controller_ = nullptr;
};
