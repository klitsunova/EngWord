#include "menu.h"

#include <QString>

#include "helpers/fonts.h"
#include "helpers/sizes.h"
#include "helpers/styles.h"

Menu::Menu(QWidget* parent) : QWidget(parent),
                              main_layout_(new QVBoxLayout(this)),
                              title_label_(new QLabel("Duolingo", this)),
                              pick_mod_button_(new QPushButton("Pick-an-Option Mode", this)),
                              input_mod_button_(new QPushButton("Input-Answer Mode", this)),
                              audio_mod_button_(new QPushButton("Audio Mode", this)),
                              mixed_mod_button_(new QPushButton("Mixed Mode", this)),
                              settings_button_(new QPushButton("SettingsView", this)),
                              exit_button_(new QPushButton("Exit", this)),
                              score_label_(new QLabel(this)) {
  SetStyles();
  SetLayout();
  ConnectUI();
}

void Menu::SetStyles() {
  setMinimumSize(menu_sizes::kMenuSize);
  title_label_->setFont(fonts::kTitleFont);
  title_label_->setStyleSheet(styles::kTitleLabel);
  score_label_->setStyleSheet(styles::kTitleLabel);
  for (auto& widget: children()) {
    auto* button_ptr = qobject_cast<QPushButton*>(widget);
    if (button_ptr != nullptr) {
      button_ptr->setFont(fonts::kButtonFont);
      button_ptr->setMinimumSize(button_sizes::kButtonSize);
      button_ptr->setStyleSheet(styles::kPushButtonStyle);
    }
  }
}

void Menu::SetLayout() {
  main_layout_->setSpacing(menu_sizes::kMenuSpacing);
  main_layout_->addStretch(5);
  main_layout_->addWidget(title_label_, 1, Qt::AlignCenter);
  main_layout_->addWidget(score_label_, 1, Qt::AlignRight);
  main_layout_->addStretch(10);
  main_layout_->addWidget(pick_mod_button_, 1, Qt::AlignCenter);
  main_layout_->addWidget(input_mod_button_, 1, Qt::AlignCenter);
  main_layout_->addWidget(audio_mod_button_, 1, Qt::AlignCenter);
  main_layout_->addWidget(mixed_mod_button_, 1, Qt::AlignCenter);
  main_layout_->addWidget(settings_button_, 1, Qt::AlignCenter);
  main_layout_->addWidget(exit_button_, 1, Qt::AlignCenter);
  main_layout_->addStretch(10);
}

void Menu::ConnectUI() {
  connect(pick_mod_button_,
          &QPushButton::clicked,
          this,
          &Menu::PickModButtonPressed);
  connect(input_mod_button_,
          &QPushButton::clicked,
          this,
          &Menu::InputModButtonPressed);
  connect(audio_mod_button_,
          &QPushButton::clicked,
          this,
          &Menu::AudioModButtonPressed);
  connect(mixed_mod_button_,
          &QPushButton::clicked,
          this,
          &Menu::MixedModButtonPressed);
  connect(settings_button_,
          &QPushButton::clicked,
          this,
          &Menu::SettingsButtonPressed);
  connect(exit_button_,
          &QPushButton::clicked,
          this,
          &Menu::ExitButtonPressed);
}

void Menu::SetScoreLabel(QString score) {
  score_label_->setText("Score: " + score);
}
