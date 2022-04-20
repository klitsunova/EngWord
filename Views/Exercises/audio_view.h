#pragma once

#include <QAudioOutput>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>
#include <QWidget>

#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

class AudioView : public QWidget {
  Q_OBJECT

 public:
  AudioView();
  ~AudioView() override = default;

  void SetAudioPath(QString path);

  QString GetAnswer();

  void PlaySound();

 private:
  QPushButton* play_;
  QHBoxLayout* layout_;
  QTextEdit* form_;
  QMediaPlayer* player_;
  QString audio_path_;
};