#include "words.h"

Word::Word(
    QString text_input,
    QString translation_input,
    QString audio_path_input) : text_(text_input),
                                translation_(translation_input),
                                audio_path_(audio_path_input) {
}

QString Word::GetText() const {
  return text_;
}

void Word::SetText(QString text_input) {
  text_ = std::move(text_input);
}

QString Word::GetTranslation() const {
  return translation_;
}

void Word::SetTranslation(QString translation_input) {
  translation_ = std::move(translation_input);
}

QString Word::GetAudioPath() const {
  return audio_path_;
}

void Word::SetAudioPath(QString audio_path_input) {
  audio_path_ = std::move(audio_path_input);
}

WordSet::WordSet() {
}

void WordSet::GetWordsData() {
  QFile file;
  if (Settings::GetLevelSettings() == easy) {
    file.setFileName(":/words/easy.json");
  } else {
    file.setFileName(":/words/hard.json");
  }
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QByteArray data = file.readAll();
  file.close();

  QJsonParseError errorPtr;
  QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
  QJsonObject rootObj = doc.object();
  QJsonArray ptsArray = rootObj.value("words").toArray();

  foreach (const auto& val, ptsArray) {
    QString text = val.toObject().value("text").toString();
    QString translation = val.toObject().value("translation").toString();
    QString audio = val.toObject().value("audio").toString();
    words_.push_back(Word(text, translation, audio));
  }
}

QVector<std::pair<Word, mode>>* WordSet::CreateExercisesSet(
    mode mode_input,
    int exercise_amount) {
  auto* result = new QVector<std::pair<Word, mode>>;
  QRandomGenerator* generator = QRandomGenerator::global();
  for (size_t i = 0; i < exercise_amount; ++i) {
    Word generated_word = words_[generator->bounded(0, words_.size())];
    mode generated_mode;
    if (mode_input != mixed) {
      generated_mode = mode_input;
    } else {
      generated_mode = Settings::ToMode(generator->bounded(0, 3));
    }
    result->push_back(std::make_pair(generated_word, generated_mode));
  }
  return result;
}

QVector<Word>* WordSet::GetThreeRandomWords(QString text) {
  auto result = new QVector<Word>;
  QRandomGenerator* generator = QRandomGenerator::global();
  while (result->size() != 4) {
    Word generated_word = words_[generator->bounded(0, words_.size())];
    if (generated_word.GetText() != text) {
      result->push_back(generated_word);
    }
  }
  return result;
}
