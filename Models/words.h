#pragma once

#include <QVector>

#include "settings.h"

class Word {
 public:
  Word(
      QString text_input,
      QString translation_input,
      QString audio_path_input);
  ~Word() = default;

  [[nodiscard]] QString GetText() const;
  [[nodiscard]] QString GetTranslation() const;
  [[nodiscard]] QString GetAudioPath() const;

 private:
  QString text_;
  QString translation_;
  QString audio_path_;
};

class WordSet {
 public:
  WordSet();
  ~WordSet() = default;

  void GetWordsData();
  QVector<std::pair<Word, Mode>>* CreateExercisesSet(
      Mode mode_input,
      int exercise_amount);

  QVector<Word>* GetThreeRandomWords(QString text);

 private:
  QVector<Word> words_;
};
