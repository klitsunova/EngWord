#pragma once

#include <QMainWindow>
#include <QMediaPlayer>

#include "Models/exercises_set.h"
#include "Models/words.h"
#include "Views/Exercises/exercises_set_view.h"

class ExercisesController : public QMainWindow {
  Q_OBJECT

 public:
  ExercisesController();
  ~ExercisesController() override = default;

  void StartExerciseSet(Mode input_mode);

  void CheckAnswer();
  void NextQuestion();

  void CloseView();

 signals:
  void Back();

 private:
  void ConnectUI();

  ExercisesSetView* view_ = nullptr;
  ExercisesSet* model_ = nullptr;
  WordSet* word_set_ = nullptr;
  QMediaPlayer* player_ = nullptr;
  int exercises_amount_ = 10;
  int current_task_ = 0;
  int correct_answers_ = 0;
};
