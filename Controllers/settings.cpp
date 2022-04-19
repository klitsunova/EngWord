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

void Settings::SetDefaultSettings() {
  SetSoundSetting(true);
  SetScore(0);
  SetLevel(level::easy);
}

void Settings::SetSettings(level level_input,
                           bool sound_input,
                           int score_input) {
  SetSoundSetting(sound_input);
  SetScore(score_input);
  SetLevel(level_input);
}

Settings::level Settings::GetLevel() {
  QSettings settings;
  int level = settings.value("level").toInt();
  return (level == 0) ? easy : hard;
}

void Settings::SetLevel(Settings::level level_input) {
  QSettings settings;
  settings.setValue("level", level_input);
}

bool Settings::GetSoundSetting() {
  QSettings settings;
  return settings.value("sound").toBool();
}

void Settings::SetSoundSetting(bool sound_input) {
  QSettings settings;
  settings.setValue("sound", sound_input);
}
