#pragma once

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>

#include "Models/settings.h"

#include "Views/Exercises/audio_view.h"
#include "Views/Exercises/input_view.h"
#include "Views/Exercises/pick_view.h"

class ExercisesSetView : public QWidget {
  Q_OBJECT
 public:
  ExercisesSetView();
  ~ExercisesSetView() override = default;

  void AddPickWidget(PickView* input);
  void AddInputWidget(InputView* input);
  void AddAudioWidget(AudioView* input);

  void SetDefaultWidget();
  void SetWidget(int index);

  void SetProgressBarMax(int value);
  QString GetAnswer(Mode input_mode);
  void ShowCorrect(bool is_correct, QString correct_text);
  void UpdateAttemptsLabel(int attempts_left);
  void ShowAnimation();

 signals:
  void ReadyButtonPressed();
  void BackButtonPressed();
  void ContinueButtonPressed();
  void PlayAudio();

 private:
  void SetLayouts();
  void SetStyles();
  void ConnectUI();

 private:
  QStackedWidget* stacked_widgets_;
  QProgressBar* progress_bar_;
  QPushButton* ready_button_;
  QLabel* attempts_label_;
  QLabel* is_correct_label_;
  QPushButton* back_button_;
  QPushButton* continue_button_;
};
