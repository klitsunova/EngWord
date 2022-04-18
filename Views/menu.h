#pragma once

#include <QLabel>
#include <QPushButton>
#include <QSettings>
#include <QVBoxLayout>
#include <QWidget>

#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

class Menu : public QWidget {
  Q_OBJECT

 public:
  explicit Menu(QWidget* parent = nullptr);
  ~Menu() override = default;

 signals:
  void PickModButtonPressed();
  void InputModButtonPressed();
  void AudioModButtonPressed();
  void MixedModButtonPressed();
  void SettingsButtonPressed();
  void ExitButtonPressed();

 private:
  void SetStyles();
  void SetLayout();
  void ConnectUI();

  QVBoxLayout* main_layout_ = nullptr;
  QLabel* title_label_ = nullptr;
  QLabel* score_label_ = nullptr;
  QPushButton* pick_mod_button_ = nullptr;
  QPushButton* input_mod_button_ = nullptr;
  QPushButton* audio_mod_button_ = nullptr;
  QPushButton* mixed_mod_button_ = nullptr;
  QPushButton* settings_button_ = nullptr;
  QPushButton* exit_button_ = nullptr;
};
