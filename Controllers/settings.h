#pragma once

#include <QSettings>

enum level {
  easy,
  hard,
};

enum mode {
  pick,
  input,
  audio,
  mixed,
};

class Settings {
 public:
  static int GetScoreInt();
  static QString GetScoreString();
  static void SetScore(int score_input);

  static level GetLevelSettings();
  static void SetLevel(level level_input);

  static bool GetSoundSetting();
  static void SetSoundSetting(bool sound_input);

  static mode ToMode(int int_input);

  static void SetDefaultSettings();
  static void SetSettings(
      level level_input,
      bool sound_input,
      int score_input);
};
