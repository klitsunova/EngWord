#include "input_view.h"

InputView::InputView() : layout_(new QVBoxLayout(this)),
                         task_(new QLabel(this)),
                         form_(new QTextEdit(this)) {
  task_->setFont(fonts::kLabelFont);
  layout_->addWidget(task_);
  layout_->addWidget(form_);
}

void InputView::SetTask(QString input) {
  task_->setText("Translate: " + input);
}

QString InputView::GetAnswer() {
  return form_->toPlainText();
}