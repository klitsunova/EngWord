#pragma once

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>

#include "helpers/fonts.h"
#include "helpers/styles.h"

#include "Views/Exercises/audio_view.h"
#include "Views/Exercises/input_view.h"
#include "Views/Exercises/pick_view.h"

class ExercisesSetView : public QWidget {
  Q_OBJECT
 public:
  ExercisesSetView();
  ~ExercisesSetView() override = default;

 signals:
  void ReadyButtonPressed();
  void BackButtonPressed();
  void ContinueButtonPressed();

  //void SetExercises(std::vector<Exercise> exercises);
 private:
  void SetWidgets();
  void SetLayouts();
  void SetStyles();
  void ConnectUI();


 private:
  QStackedWidget* stacked_widgets_;
  QProgressBar* progress_bar_;
  QPushButton* ready_button_;
  QLabel* attempts_label_;
  QPushButton* back_button_;
  QPushButton* continue_button_;
};
