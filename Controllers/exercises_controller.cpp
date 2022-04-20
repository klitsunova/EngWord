#include "exercises_controller.h"

ExercisesController::ExercisesController() : view_(new ExercisesSetView()),
                                             model_(new ExercisesSet()),
                                             word_set_(new WordSet()) {
  ConnectUI();
}

void ExercisesController::StartExerciseSet(mode input_mode) {
  word_set_->GetWordsData();
  model_->SetWordsSet(word_set_->CreateExercisesSet(input_mode, exercises_amount_));
  view_->SetProgressBarMax(exercises_amount_);
  for (const auto& task : *model_->GetWordsSet()) {
    switch (task.second) {
      case pick: {
        auto* new_view = new PickView;
        QVector<Word>* variants = word_set_->GetThreeRandomWords(task.first.GetText());
        new_view->SetFirst((*variants)[0].GetText());
        new_view->SetSecond((*variants)[1].GetText());
        new_view->SetThird((*variants)[2].GetText());
        new_view->SetFourth(task.first.GetText());
        new_view->SetTask(task.first.GetTranslation());
        view_->AddPickWidget(new_view);
      }
    }
  }
  view_->SetDefaultWidget();
  view_->show();
}

void ExercisesController::ConnectUI() {
  connect(view_,
          &ExercisesSetView::ReadyButtonPressed,
          this,
          &ExercisesController::CheckAnswer);
  connect(view_,
          &ExercisesSetView::BackButtonPressed,
          this,
          &ExercisesController::Back);
  connect(view_,
          &ExercisesSetView::ContinueButtonPressed,
          this,
          &ExercisesController::NextQuestion);
}

void ExercisesController::CheckAnswer() {
  QString correct_answer = model_->GetCorrectAnswer(current_task_);
  mode current_mode = model_->GetMode(current_task_);
  QString checked_answer = view_->GetAnswer(current_mode);
  if (correct_answer == checked_answer) {
    view_->ShowCorrect(true, correct_answer);
    ++correct_answers_;
  } else {
    view_->ShowCorrect(false, correct_answer);
    model_->RemoveAttempt();
  }
}

void ExercisesController::NextQuestion() {
  if (current_task_ < exercises_amount_) {
    ++current_task_;
    view_->SetWidget(current_task_);
  }
  else {
    Settings::SetScore(Settings::GetScoreInt() + correct_answers_);

    Back();
  }
}

void ExercisesController::CloseView() {
  view_->close();
}
