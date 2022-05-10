#include "settings.h"

int Settings::GetScoreInt() {
  QSettings settings;
  return settings.value("score").toInt();
}

QString Settings::GetScoreString() {
  QSettings settings;
  return settings.value("score").toString();
}

void Settings::SetScore(int score) {
  QSettings settings;
  settings.setValue("score", score);
}

void Settings::SetSettings(Level level_input,
                           bool sound_input,
                           int score_input) {
  SetSoundSetting(sound_input);
  SetScore(score_input);
  SetLevel(level_input);
}

Level Settings::GetLevelSettings() {
  QSettings settings;
  int level = settings.value("level").toInt();
  return (level == 0) ? Level::kEasy : Level::kHard;
}

void Settings::SetLevel(Level level_input) {
  QSettings settings;
  settings.setValue("level", static_cast<int>(level_input));
}

bool Settings::GetSoundSetting() {
  QSettings settings;
  return settings.value("sound").toBool();
}

void Settings::SetSoundSetting(bool sound_input) {
  QSettings settings;
  settings.setValue("sound", sound_input);
}

Mode Settings::ToMode(int int_input) {
  switch (int_input) {
    case 0: return Mode::kPick;
    case 1: return Mode::kInput;
    default: return Mode::kAudio;
  }
}
