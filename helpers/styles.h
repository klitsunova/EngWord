#pragma once

#include <QRadioButton>
#include <QString>

namespace styles {

const QString kPushButtonStyle =
    "QPushButton {"
    "background-color: #58cc02;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-radius: 10px;"
    "border-color: #58a700;"
    "padding: 2px;"
    "font: bold 18px;"
    "color: white; }"

    "QPushButton::pressed {"
    "background-color: #58a700;"
    "border-style: inset; }";

const QString kBluePushButtonStyle =
    "QPushButton {"
    "background-color: #00A6F9;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-radius: 10px;"
    "border-color: #0073F9;"
    "padding: 2px;"
    "font: bold 18px;"
    "color: white; }"

    "QPushButton::pressed {"
    "background-color: #0073F9;"
    "border-style: inset; }";

const QString kCancelPushButtonStyle =
    "QPushButton {"
    "background-color: #EF615B;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-radius: 10px;"
    "border-color: #DB312A;"
    "padding: 2px;"
    "font: bold 18px;"
    "color: white; }"

    "QPushButton::pressed {"
    "background-color: #58a700;"
    "border-style: inset; }";

const QString kRadioButtonStyle =
    "QRadioButton::indicator {"
    "width: 40px;"
    "height: 40px; }"

    "QRadioButton::indicator::unchecked {"
    "image: url(../resources/images/Settings/radiobutton_unchecked.png); }"

    "QRadioButton::indicator::checked {"
    "image: url(../resources//images/Settings/radiobutton_checked.png); }";

const QString kSwitchStyle =
    "QCheckBox::indicator {"
    "width: 80px;"
    "height: 40px; }"

    "QCheckBox::indicator::unchecked {"
    "image: url(../resources/images/Settings/switch_unchecked.png); }"

    "QCheckBox::indicator::checked {"
    "image: url(../resources//images/Settings/switch_checked.png); }";

const QString kTitleLabel =
    "QLabel {"
    "color: white; }";
} // namespace styles
