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

class ExercisesController : QMainWindow {
  Q_OBJECT

 public:
  ExercisesController();
  ~ExercisesController() override = default;

  void StartExerciseSet(mode input_mode);

 private:
  void SetWidgets();
  void ConnectUI();

 private:
  ExercisesSetView* view_ = nullptr;
  ExercisesSet* model_ = nullptr;
  WordSet* word_set_ = nullptr;
  int exercises_amount = 10;
};
