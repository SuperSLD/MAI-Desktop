#include "numweekwidget.h"

#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>

#include <stylecontainer.h>
using namespace styles;

NumWeekWidget::NumWeekWidget (QString numWeek, bool current) {
    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);   // назначение главного лейута

    QLabel *mainLabel = new QLabel(numWeek);
    mainLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
    );
    mainLabel->setAlignment(Qt::AlignHCenter);
    mainLabel->setFont(QFont("Roboto", 48, QFont::Bold));
    mainVLayout->addWidget(mainLabel);

    QLabel *weekLabel = new QLabel("Неделя №"+ numWeek);
    weekLabel->setAlignment(Qt::AlignHCenter);
    weekLabel->setFont(QFont("Roboto", 18));
    mainVLayout->addWidget(weekLabel);

    this->setFixedHeight(164);
    this->setFixedWidth(221);

    if (current) {
        this->setStyleSheet(
            "background-color:" + COLOR_PRIMARY + ";"
            "border:none;"
            "padding:0px;"
        );
        weekLabel->setStyleSheet(
            "color:white;"
        );
    } else {
        this->setStyleSheet(
            "background-color:#343434;"
            "border:none;"
            "padding:0px;"
        );
        weekLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
    };

    // Добавление тени
//    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
//    effect->setXOffset(4);
//    effect->setYOffset(4);
//    effect->setBlurRadius(20);
//    effect->setColor(QColor(0, 0, 0, 60));
//    this->setGraphicsEffect(effect);
}
