#pragma once

#include <QAction>
#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMouseEvent>
#include <QPushButton>
#include <QRadioButton>
#include <QSettings>
#include <QVBoxLayout>
#include <QWidget>

#include "Controllers/settings.h"

#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

class ClickableLabel : public QLabel {
  Q_OBJECT

 public:
  explicit ClickableLabel(
      const QString& text = "",
      QWidget* parent = nullptr);
  ~ClickableLabel() override = default;

 signals:
  void clicked(QMouseEvent*);

 protected:
  void mousePressEvent(QMouseEvent* event) override;
};

class SettingsView : public QWidget {
  Q_OBJECT

 public:
  explicit SettingsView(QWidget* parent = nullptr);
  ~SettingsView() override = default;

  level GetLevelSettings() const;
  bool GetSoundSettings() const;
  int GetScoreSettings() const;
  void GetSettingsView();

 private:
  void SetStyles();
  void SetLayout();
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

 public slots:
  void ResetScore();

 private:
  void contextMenuEvent();

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
  ClickableLabel* score_label_;
  QPushButton* reset_score_button_;
  QPushButton* accept_button_;
  QPushButton* cancel_button_;
  QMenu* context_menu_;
  QAction* reset_score_;
};
