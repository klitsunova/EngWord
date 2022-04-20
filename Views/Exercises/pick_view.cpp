#include "pick_view.h"

PickView::PickView() : task_(new QLabel(this)),
                       layout_(new QVBoxLayout(this)),
                       first_(new QRadioButton(this)),
                       second_(new QRadioButton(this)),
                       third_(new QRadioButton(this)),
                       fourth_(new QRadioButton(this)) {
  SetStyles();
  SetLayout();
  ConnectUI();
}

void PickView::SetStyles() {
  task_->setFont(fonts::kLabelFont);
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

void PickView::ConnectUI() {
  // connect(first_,
  //         &::QRadioButton::clicked,
  //         this,
  //         &PickView::FirstChecked);
  // connect(second_,
  //         &::QRadioButton::clicked,
  //         this,
  //         &PickView::FirstChecked);
  // connect(third_,
  //         &::QRadioButton::clicked,
  //         this,
  //         &PickView::FirstChecked);
  // connect(fourth_,
  //         &::QRadioButton::clicked,
  //         this,
  //         &PickView::FirstChecked);
}

void PickView::SetTask(QString input) {
  task_->setText("Translate: " + input);
}

void PickView::SetFirst(QString input) {
  first_->setText(input);
}

void PickView::SetSecond(QString input) {
  second_->setText(input);
}

void PickView::SetThird(QString input) {
  third_->setText(input);
}

void PickView::SetFourth(QString input) {
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
  return QString();
}

QString PickView::GetFirst() {
  return first_->text();
}

QString PickView::GetSecond() {
  return second_->text();
}

QString PickView::GetThird() {
  return third_->text();
}

QString PickView::GetFourth() {
  return fourth_->text();
}