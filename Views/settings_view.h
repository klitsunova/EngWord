#pragma once

#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QSettings>
#include <QVBoxLayout>
#include <QWidget>

#include "Controllers/settings.h"

#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

class SettingsView : public QWidget {
  Q_OBJECT

 public:
  explicit SettingsView(QWidget* parent = nullptr);
  ~SettingsView() override = default;

  Settings::level GetLevelSettings() const;
  bool GetSoundSettings() const;
  int GetScoreSettings() const;

 private:
  void SetStyles();
  void SetLayout();
  void GetSettings();
  void ConnectUI();

  void SetLevelLayout();
  void SetSoundLayout();
  void SetScoreLayout();
  void SetDialogButtonsLayout();

  void SetLevelStyles();
  void SetSoundStyles();
  void SetScoreStyles();
  void SetDialogButtonStyles();

  void SetScoreLabel();
  void ResetScore();

 signals:
  void ApplyChanges();
  void CloseSettings();

 private:
  QGridLayout* layout_;
  QLabel* level_label_;
  QRadioButton* easy_mode_;
  QRadioButton* hard_mode_;
  QLabel* sound_label_;
  QCheckBox* sound_;
  int score_;
  QLabel* score_label_;
  QPushButton* reset_score_button_;
  QPushButton* accept_button_;
  QPushButton* cancel_button_;
};
