#pragma once

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "helpers/fonts.h"

class InputView : public QWidget {
  Q_OBJECT

 public:
  InputView();
  ~InputView() override = default;

  void SetTask(QString input);
  QString GetAnswer();

 private:
  QVBoxLayout* layout_;
  QLabel* task_;
  QTextEdit* form_;
};