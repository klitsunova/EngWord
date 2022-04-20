#include "exercises_set_view.h"

ExercisesSetView::ExercisesSetView() : progress_bar_(new QProgressBar(this)),
                                       ready_button_(new QPushButton(this)),
                                       attempts_label_(new QLabel(this)),
                                       back_button_(new QPushButton(this)),
                                       continue_button_(new QPushButton(this)) {

  SetWidgets();
  // SetStyles();
  // SetLayout();
  // ConnectUI();
}
void ExercisesSetView::SetWidgets() {
}

void ExercisesSetView::SetLayouts() {
}

void ExercisesSetView::SetStyles() {
}
void ExercisesSetView::ConnectUI() {
}
