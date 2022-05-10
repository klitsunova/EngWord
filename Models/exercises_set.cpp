#include "exercises_set.h"

ExercisesSet::ExercisesSet() {
}

void ExercisesSet::RemoveAttempt() {
  --attempts_left_;
}

int ExercisesSet::GetAttempts() const {
  return attempts_left_;
}

bool ExercisesSet::IsZeroAttemptsLeft() const {
  if (attempts_left_ == 0) {
    return true;
  }
  return false;
}

void ExercisesSet::SetWordsSet(QVector<std::pair<Word, Mode>>* input) {
  words_set_ = input;
}

QVector<std::pair<Word, Mode>>* ExercisesSet::GetWordsSet() {
  return words_set_;
}

QString ExercisesSet::GetCorrectAnswer(int index) {
  return words_set_->at(index).first.GetText();
}

Mode ExercisesSet::GetMode(int index) {
  return words_set_->at(index).second;
}
