#include "audio_view.h"

#include <QAudioOutput>
#include <utility>

#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

AudioView::AudioView() : play_(new QPushButton("Play", this)),
                         form_(new QTextEdit(this)),
                         layout_(new QHBoxLayout(this)),
                         player_(new QMediaPlayer()) {
  layout_->addWidget(play_);
  play_->setStyleSheet(styles::kPushButtonStyle);
  play_->setFont(fonts::kButtonFont);
  play_->setMinimumSize(button_sizes::kButtonSize);
  layout_->addWidget(form_);
  auto audioOutput = new QAudioOutput;
  player_->setAudioOutput(audioOutput);
  audioOutput->setVolume(50);
  connect(play_,
          &QPushButton::clicked,
          this,
          &AudioView::PlaySound);
}

QString AudioView::GetAnswer() {
  return form_->toPlainText();
}

void AudioView::SetAudioPath(QString path) {
  audio_path_ = std::move(path);
}

void AudioView::PlaySound() {
  player_->setSource(QUrl::fromLocalFile(audio_path_));
  player_->play();
}
