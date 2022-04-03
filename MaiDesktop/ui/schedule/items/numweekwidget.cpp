#include "numweekwidget.h"

#include <QHBoxLayout>
#include <qlabel.h>

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
        "font-size: 48px;"
    );
    mainLabel->setAlignment(Qt::AlignHCenter);
    mainVLayout->addWidget(mainLabel);

    QLabel *weekLabel = new QLabel("Неделя №"+ numWeek);
    weekLabel->setAlignment(Qt::AlignHCenter);
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
            "font-size:18px;"
        );
    } else {
        this->setStyleSheet(
            "background-color:#343434;"
            "border:none;"
            "padding:0px;"
        );
        weekLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:18px;"
        );
    };
}
