#include "exercises_set_view.h"

#include <QPainter>

#include "Views/Exercises/animation.h"
#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

ExercisesSetView::ExercisesSetView() : stacked_widgets_(new QStackedWidget(this)),
                                       progress_bar_(new QProgressBar(this)),
                                       ready_button_(new QPushButton("Check", this)),
                                       attempts_label_(new QLabel(this)),
                                       back_button_(new QPushButton("Back", this)),
                                       continue_button_(new QPushButton("Continue", this)),
                                       is_correct_label_(new QLabel(this)) {
  setMinimumSize(window_sizes::kScreenSizeDefault);
  setWindowTitle("Duolingo Exercises");
  setWindowIcon(QIcon(":/images/MainWindow/icon.svg"));
  SetStyles();
  SetLayouts();
  ConnectUI();
}

void ExercisesSetView::SetLayouts() {
  auto* layout = new QVBoxLayout();
  layout->addWidget(progress_bar_);
  layout->addStretch(5);
  layout->addWidget(attempts_label_, 0, Qt::AlignRight);
  layout->addStretch(5);
  layout->addWidget(stacked_widgets_, 0, Qt::AlignCenter);
  layout->addWidget(is_correct_label_, 0, Qt::AlignCenter);
  is_correct_label_->hide();
  auto* button_layout = new QHBoxLayout();
  button_layout->addWidget(back_button_);
  button_layout->addWidget(ready_button_);
  button_layout->addWidget(continue_button_);
  layout->addStretch(5);
  layout->addLayout(button_layout, 0);
  setLayout(layout);
}

void ExercisesSetView::SetStyles() {
  setAutoFillBackground(true);
  const QPalette palette(qRgb(227, 227, 216));
  setPalette(palette);

  is_correct_label_->setFont(fonts::kLabelFont);
  ready_button_->setFont(fonts::kButtonFont);
  ready_button_->setMinimumSize(button_sizes::kButtonSize);
  ready_button_->setStyleSheet(styles::kPushButtonStyle);

  back_button_->setFont(fonts::kButtonFont);
  back_button_->setMinimumSize(button_sizes::kButtonSize);
  back_button_->setStyleSheet(styles::kBluePushButtonStyle);

  continue_button_->setFont(fonts::kButtonFont);
  continue_button_->setMinimumSize(button_sizes::kButtonSize);
  continue_button_->setStyleSheet(styles::kPushButtonStyle);
}

void ExercisesSetView::ConnectUI() {
  connect(ready_button_,
          &QPushButton::clicked,
          this,
          &ExercisesSetView::ReadyButtonPressed);
  connect(back_button_,
          &QPushButton::clicked,
          this,
          &ExercisesSetView::BackButtonPressed);
  connect(continue_button_,
          &QPushButton::clicked,
          this,
          &ExercisesSetView::ContinueButtonPressed);
}

void ExercisesSetView::AddPickWidget(PickView* input) {
  stacked_widgets_->addWidget(input);
}

void ExercisesSetView::AddInputWidget(InputView* input) {
  stacked_widgets_->addWidget(input);
}

void ExercisesSetView::AddAudioWidget(AudioView* input) {
  stacked_widgets_->addWidget(input);
}

void ExercisesSetView::SetDefaultWidget() {
  stacked_widgets_->setCurrentIndex(0);
}

void ExercisesSetView::SetWidget(int index) {
  is_correct_label_->hide();
  stacked_widgets_->setCurrentIndex(index);
  progress_bar_->setValue(index);
}

void ExercisesSetView::SetProgressBarMax(int value) {
  progress_bar_->setMaximum(value);
}

QString ExercisesSetView::GetAnswer(Mode input_mode) {
  switch (input_mode) {
    case Mode::kPick: {
      auto* widget = dynamic_cast<PickView*>(stacked_widgets_->currentWidget());
      return widget->GetChecked();
    }
    case Mode::kInput: {
      auto widget = dynamic_cast<InputView*>(stacked_widgets_->currentWidget());
      return widget->GetAnswer();
    }
    case Mode::kAudio: {
      auto* widget = dynamic_cast<AudioView*>(stacked_widgets_->currentWidget());
      return widget->GetAnswer();
    }
  }
}

void ExercisesSetView::ShowCorrect(bool is_correct, QString correct_text) {
  if (is_correct) {
    is_correct_label_->setText("Great!");
  } else {
    is_correct_label_->setText("Ooops... Correct is " + correct_text);
  }
  is_correct_label_->show();
}

void ExercisesSetView::UpdateAttemptsLabel(int attempts_left) {
  attempts_label_->setText("Attempts left: " + QString::number(attempts_left));
}

void ExercisesSetView::ShowAnimation() {
  auto* animation = new Animation();
  stacked_widgets_->addWidget(animation);
  stacked_widgets_->setCurrentWidget(animation);
}
