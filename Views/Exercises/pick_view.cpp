#include "pick_view.h"

#include "helpers/fonts.h"
#include "helpers/styles.h"

PickView::PickView() : task_(new QLabel(this)),
                       layout_(new QVBoxLayout(this)),
                       first_(new QRadioButton(this)),
                       second_(new QRadioButton(this)),
                       third_(new QRadioButton(this)),
                       fourth_(new QRadioButton(this)) {
  SetStyles();
  SetLayout();
}

void PickView::SetStyles() {
  task_->setFont(fonts::kLabelFont);
  // TODO: rewrite with loop
  first_->setStyleSheet(styles::kRadioButtonStyle);
  first_->setFont(fonts::kSmallLabelFont);
  second_->setStyleSheet(styles::kRadioButtonStyle);
  second_->setFont(fonts::kSmallLabelFont);
  third_->setStyleSheet(styles::kRadioButtonStyle);
  third_->setFont(fonts::kSmallLabelFont);
  fourth_->setStyleSheet(styles::kRadioButtonStyle);
  fourth_->setFont(fonts::kSmallLabelFont);
}

void PickView::SetLayout() {
  layout_->addWidget(task_);
  layout_->addWidget(first_);
  layout_->addWidget(second_);
  layout_->addWidget(third_);
  layout_->addWidget(fourth_);
}

void PickView::SetTask(const QString& input) {
  task_->setText("Translate: " + input);
}

void PickView::SetFirst(const QString& input) {
  first_->setText(input);
}

void PickView::SetSecond(const QString& input) {
  second_->setText(input);
}

void PickView::SetThird(const QString& input) {
  third_->setText(input);
}

void PickView::SetFourth(const QString& input) {
  fourth_->setText(input);
}

QString PickView::GetChecked() {
  if (first_->isChecked()) {
    return first_->text();
  }
  if (second_->isChecked()) {
    return second_->text();
  }
  if (third_->isChecked()) {
    return third_->text();
  }
  if (fourth_->isChecked()) {
    return fourth_->text();
  }
  return {};
}
