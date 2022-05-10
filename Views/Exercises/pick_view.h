#pragma once

#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QWidget>

class PickView : public QWidget {
  Q_OBJECT
 public:
  PickView();
  ~PickView() override = default;

  void SetStyles();
  void SetLayout();

  void SetTask(const QString& input);
  void SetFirst(const QString& input);
  void SetSecond(const QString& input);
  void SetThird(const QString& input);
  void SetFourth(const QString& input);

  QString GetChecked();

 private:
  QLabel* task_;
  QVBoxLayout* layout_;
  QRadioButton* first_;
  QRadioButton* second_;
  QRadioButton* third_;
  QRadioButton* fourth_;
};
