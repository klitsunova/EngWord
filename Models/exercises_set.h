#pragma once

#include <QVector>

#include "Models/words.h"

class ExercisesSet {
 public:
  ExercisesSet();
  ~ExercisesSet() = default;

  void RemoveAttempt();
  int GetAttempts() const;
  bool IsZeroAttemptsLeft() const;

  void SetWordsSet(QVector<std::pair<Word, mode>>* input);

 private:
  QVector<std::pair<Word, mode>>* words_set_;
  int attempts_left_ = 3;
};
