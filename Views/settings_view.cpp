#include "settings_view.h"

SettingsView::SettingsView(QWidget* parent) : QWidget(parent),
                                              layout_(new QGridLayout(this)),
                                              level_label_(new QLabel("Difficulty", this)),
                                              easy_mode_(new QRadioButton("Easy", this)),
                                              hard_mode_(new QRadioButton("Hard", this)),
                                              sound_label_(new QLabel("Sound", this)),
                                              sound_(new QCheckBox("On", this)),
                                              score_label_(new ClickableLabel()),
                                              score_(Settings::GetScoreInt()),
                                              reset_score_button_(new QPushButton("Reset score", this)),
                                              accept_button_(new QPushButton("Apply", this)),
                                              cancel_button_(new QPushButton("Cancel", this)),
                                              context_menu_(new QMenu(this)),
                                              reset_score_(new QAction("Reset score", this)) {
  SetStyles();
  SetLayout();
  GetSettingsView();
  ConnectUI();
}

void SettingsView::SetStyles() {
  setAutoFillBackground(true);
  const QPalette palette(qRgb(227, 227, 216));
  setPalette(palette);
  SetLevelStyles();
  SetSoundStyles();
  SetScoreStyles();
  SetDialogButtonStyles();
  context_menu_->setStyleSheet(styles::kContextMenu);
}

void SettingsView::SetLayout() {
  SetLevelLayout();
  SetSoundLayout();
  SetScoreLayout();
  SetDialogButtonsLayout();
  context_menu_->addAction(reset_score_);
}

void SettingsView::contextMenuEvent() {
  context_menu_->popup(QCursor::pos());
}

void SettingsView::GetSettingsView() {
  if (Settings::GetLevel() == Settings::level::easy) {
    easy_mode_->setChecked(true);
  } else {
    hard_mode_->setChecked(true);
  }
  if (Settings::GetSoundSetting()) {
    sound_->setChecked(true);
  } else {
    sound_->setChecked(false);
  };
  score_ = Settings::GetScoreInt();
  SetScoreLabel();
}

void SettingsView::ConnectUI() {
  connect(accept_button_,
          &QPushButton::clicked,
          this,
          &SettingsView::ApplyChanges);
  connect(cancel_button_,
          &QPushButton::clicked,
          this,
          &SettingsView::CloseSettings);
  connect(reset_score_button_,
          &QPushButton::clicked,
          this,
          &SettingsView::ResetScore);
  connect(score_label_,
          &ClickableLabel::clicked,
          this,
          &SettingsView::contextMenuEvent);
  connect(reset_score_,
          &QAction::triggered,
          this,
          &SettingsView::ResetScore);
}

void SettingsView::SetLevelLayout() {
  auto* difficulty_layout = new QHBoxLayout;
  auto* mode_layout = new QVBoxLayout;
  difficulty_layout->addWidget(level_label_);
  mode_layout->addWidget(easy_mode_);
  mode_layout->addWidget(hard_mode_);
  difficulty_layout->addLayout(mode_layout);
  layout_->addLayout(difficulty_layout, 1, 1, Qt::AlignCenter);
}

void SettingsView::SetSoundLayout() {
  auto* sound_layout = new QHBoxLayout;
  sound_layout->addWidget(sound_label_);
  sound_layout->addWidget(sound_);
  layout_->addLayout(sound_layout, 2, 1, Qt::AlignCenter);
}

void SettingsView::SetScoreLayout() {
  auto* score_layout = new QVBoxLayout;
  score_layout->addWidget(score_label_);
  score_layout->addWidget(context_menu_);
  score_layout->addWidget(reset_score_button_);
  layout_->addLayout(score_layout, 3, 1, Qt::AlignCenter);
}

void SettingsView::SetDialogButtonsLayout() {
  auto* buttons_layout = new QHBoxLayout;
  buttons_layout->addWidget(accept_button_);
  buttons_layout->addWidget(cancel_button_);
  layout_->addLayout(buttons_layout, 4, 1, Qt::AlignRight);
  setLayout(layout_);
}

void SettingsView::SetLevelStyles() {
  level_label_->setFont(fonts::kLabelFont);
  easy_mode_->setStyleSheet(styles::kRadioButtonStyle);
  easy_mode_->setFont(fonts::kSmallLabelFont);
  hard_mode_->setStyleSheet(styles::kRadioButtonStyle);
  hard_mode_->setFont(fonts::kSmallLabelFont);
}

void SettingsView::SetSoundStyles() {
  sound_label_->setFont(fonts::kLabelFont);
  sound_->setStyleSheet(styles::kSwitchStyle);
}

void SettingsView::SetScoreStyles() {
  score_label_->setFont(fonts::kLabelFont);
  reset_score_button_->setFont(fonts::kButtonFont);
  reset_score_button_->setMinimumSize(button_sizes::kButtonSize);
  reset_score_button_->setStyleSheet(styles::kBluePushButtonStyle);
}

void SettingsView::SetDialogButtonStyles() {
  accept_button_->setFont(fonts::kButtonFont);
  accept_button_->setMinimumSize(button_sizes::kButtonSize);
  accept_button_->setStyleSheet(styles::kPushButtonStyle);

  cancel_button_->setFont(fonts::kButtonFont);
  cancel_button_->setMinimumSize(button_sizes::kButtonSize);
  cancel_button_->setStyleSheet(styles::kCancelPushButtonStyle);
}

Settings::level SettingsView::GetLevelSettings() const {
  return (easy_mode_->isChecked())
      ? Settings::level::easy
      : Settings::level::hard;
}

bool SettingsView::GetSoundSettings() const {
  return sound_->isChecked();
}

int SettingsView::GetScoreSettings() const {
  return score_;
}

void SettingsView::ResetScore() {
  score_ = 100;
  SetScoreLabel();
}

void SettingsView::SetScoreLabel() {
  score_label_->setText("Score: " + QString::number(score_));
}

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent) {
  setText(text);
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::RightButton) {
    emit clicked(event);
  }
}