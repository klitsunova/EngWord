#pragma once

#include <QVector>

#include "Models/words.h"

class ExercisesSet {
 public:
  ExercisesSet();
  ~ExercisesSet() = default;

  void RemoveAttempt();
  [[nodiscard]] int GetAttempts() const;
  [[nodiscard]] bool IsZeroAttemptsLeft() const;

  void SetWordsSet(QVector<std::pair<Word, Mode>>* input);

  QVector<std::pair<Word, Mode>>* GetWordsSet();

  QString GetCorrectAnswer(int index);
  Mode GetMode(int index);

 private:
  QVector<std::pair<Word, Mode>>* words_set_;
  int attempts_left_ = 3;
};
