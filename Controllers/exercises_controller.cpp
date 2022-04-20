#include "exercises_controller.h"

ExercisesController::ExercisesController() : view_(new ExercisesSetView()),
                                             model_(new ExercisesSet()),
                                             word_set_(new WordSet()) {
  setMinimumSize(main_window_sizes::kScreenSizeDefault);
  setWindowTitle("Duolingo Exercises");
  setWindowIcon(QIcon(":/images/MainWindow/icon.svg"));
  // SetWidgets();
  // ConnectUI();
}

void ExercisesController::StartExerciseSet(mode input_mode) {
  model_->SetWordsSet(word_set_->CreateExercisesSet(input_mode, exercises_amount));
  view_->show();
}
