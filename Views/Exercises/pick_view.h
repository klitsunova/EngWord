#pragma once

#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QVBoxLayout>

#include "helpers/fonts.h"
#include "helpers/styles.h"

class PickView : public QWidget {
  Q_OBJECT
 public:
  PickView();
  ~PickView() override = default;

  void SetStyles();
  void SetLayout();

  void SetTask(QString input);
  void SetFirst(QString input);
  void SetSecond(QString input);
  void SetThird(QString input);
  void SetFourth(QString input);

  QString GetFirst();
  QString GetSecond();
  QString GetThird();
  QString GetFourth();

  QString GetChecked();

  void ConnectUI();

 private:
  QLabel* task_;
  QVBoxLayout* layout_;
  QRadioButton* first_;
  QRadioButton* second_;
  QRadioButton* third_;
  QRadioButton* fourth_;
};
