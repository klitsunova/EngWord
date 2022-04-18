#pragma once

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

const QString kTitleLabel =
    "QLabel {"
    "color: white; }";
}

