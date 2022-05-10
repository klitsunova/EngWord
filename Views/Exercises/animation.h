#pragma once

#include <QLabel>
#include <QWidget>

class Animation : public QWidget {
  Q_OBJECT

 public:
  Animation();
  ~Animation() override = default;

  void paintEvent(QPaintEvent* event) override;

 private:
  QLabel* label_;
  int size_ = 0;
  bool is_increasing_ = true;
};
