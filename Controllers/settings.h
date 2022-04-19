#pragma once

#include <QSettings>

class Settings {
 public:
  enum level {
    easy,
    hard,
  };

 public:
  static int GetScoreInt();
  static QString GetScoreString();
  static void SetScore(int score_input);

  static level GetLevel();
  static void SetLevel(level level_input);

  static bool GetSoundSetting();
  static void SetSoundSetting(bool sound_input);

  static void SetDefaultSettings();
  static void SetSettings(
      level level_input,
      bool sound_input,
      int score_input);
};
