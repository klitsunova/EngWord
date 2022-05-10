#include "animation.h"

#include <QPainter>
#include <QRandomGenerator>
#include <QTimer>

#include "helpers/fonts.h"

Animation::Animation() : label_(new QLabel("Hurrah! Well done!", this)) {
  label_->setFont(fonts::kLabelFont);
  auto paintTimer = new QTimer(this);
  paintTimer->start(10);
  connect(paintTimer, SIGNAL(timeout()), this, SLOT(update()));
}

void Animation::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  QColor beige_brush = QColor(235, 222, 207);
  painter.setBrush(beige_brush);
  if (is_increasing_) {
    if (size_ != 150) {
      ++size_;
    } else {
      is_increasing_ = false;
    }
  } else {
    if (size_ != 0) {
      --size_;
    } else {
      is_increasing_ = true;
    }
  }
  painter.drawEllipse(50, 50, size_, size_);
}
