#include "infoblockwidget.h"

#include <QBoxLayout>
#include <QLabel>

#include <stylecontainer.h>
using namespace styles;

InfoBlockWidget::InfoBlockWidget(QString bigName, QString littleName, QString nameColor) {
    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);   // назначение главного лейута

    QLabel *bigLabel = new QLabel(bigName);
    bigLabel->setFont(QFont("Roboto", 48, QFont::Bold));
    bigLabel->setStyleSheet(
        "color:" + nameColor + ";"
    );
    bigLabel->setAlignment(Qt::AlignHCenter);
    mainVLayout->addWidget(bigLabel);

    QLabel *littleLabel = new QLabel(littleName);
    littleLabel->setFont(QFont("Roboto", 18));
    littleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
    );
    littleLabel->setAlignment(Qt::AlignHCenter);
    mainVLayout->addWidget(littleLabel);

    this->setFixedHeight(164);
    this->setFixedWidth(221);
}
