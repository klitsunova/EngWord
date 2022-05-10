#pragma once

#include <QSettings>

enum class Level {
  kEasy,
  kHard,
};

enum class Mode {
  kPick,
  kInput,
  kAudio,
  kMixed,
};

class Settings {
 public:
  static int GetScoreInt();
  static QString GetScoreString();
  static void SetScore(int score_input);

  static Level GetLevelSettings();
  static void SetLevel(Level level_input);

  static bool GetSoundSetting();
  static void SetSoundSetting(bool sound_input);

  static Mode ToMode(int int_input);

  static void SetSettings(
      Level level_input,
      bool sound_input,
      int score_input);
};
