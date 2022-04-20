#pragma once

#include <QFile>
#include <QMainWindow>
#include <QStackedWidget>

#include "helpers/backgrounds.h"
#include "helpers/sizes.h"

#include "Controllers/settings.h"

#include "Models/exercises_set.h"
#include "Models/words.h"

#include "Views/Exercises/exercises_set_view.h"

class ExercisesController : public QMainWindow {
  Q_OBJECT
  ExercisesSetView* view_ = nullptr;

 public:
  ExercisesController();
  ~ExercisesController() override = default;

  void StartExerciseSet(mode input_mode);

  void CheckAnswer();
  void NextQuestion();

  void CloseView();

  signals:
   void Back();


 private:
  void SetWidgets();
  void ConnectUI();

 private:
  ExercisesSet* model_ = nullptr;
  WordSet* word_set_ = nullptr;
  int exercises_amount_ = 10;
  int current_task_ = 0;
  int correct_answers_ = 0;
};
