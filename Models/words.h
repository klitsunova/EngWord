#pragma once

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>
#include <QVector>

#include <fstream>

#include "Controllers/settings.h"

class Word {
 public:
  Word(
      QString text_input,
      QString translation_input,
      QString audio_path_input);
  ~Word() = default;

  QString GetText() const;
  void SetText(QString text_input);

  QString GetTranslation() const;
  void SetTranslation(QString translation_input);

  QString GetAudioPath() const;
  void SetAudioPath(QString audio_path_input);

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
  QVector<std::pair<Word, mode>>* CreateExercisesSet(
      mode mode_input,
      int exercise_amount);

  QVector<Word>* GetThreeRandomWords(QString text);

 private:
  QVector<Word> words_;
};
