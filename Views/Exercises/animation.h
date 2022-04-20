#pragma once

#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QTimer>
#include <QWidget>

#include "helpers/fonts.h"

class Animation : public QWidget {
  Q_OBJECT

 public:
  Animation();
  ~Animation() override = default;

  void paintEvent(QPaintEvent* event);

 private:
  QLabel* label_;
  int size_ = 0;
  bool is_increasing_ = true;
};
