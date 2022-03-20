#include "dayschedulewidget.h"

#include <QHBoxLayout>
#include <QLabel>

#include <stylecontainer.h>
using namespace styles;

DayScheduleWidget::DayScheduleWidget(int countItems) {

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);  // назначение главного лейута

    for (int i=0; i<countItems; i++) {
        QHBoxLayout *itemHLayout = new QHBoxLayout;

        QFrame *line = new QFrame;
        line->setFixedWidth(24);
        line->setFixedHeight(100);
        line->setStyleSheet(
                "background-color:"+COLOR_PRIMARY+";"
        );
        itemHLayout->addWidget(line);

        QFrame *item = new QFrame;
        item->setFixedWidth(223);
        item->setFixedHeight(100);
        item->setStyleSheet("background-color:white;");

        QGridLayout *gridLayout = new QGridLayout;
        QLabel *l1 = new QLabel("Технология системного моделирования");
        l1->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:18px;"
        );
        l1->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(l1, 0, 0, 1, 2);
        QLabel *l2 = new QLabel("Топорова Мария Илларионова");
        l2->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:14px;"
        );
        l2->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(l2, 1, 0, 1, 2);
        QLabel *l3 = new QLabel("09:00 - 10:30");
        l3->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:14px;"
        );
        l3->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(l3, 2, 0, 1, 2);
        QLabel *l4 = new QLabel("--каф");
        l4->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:14px;"
        );
        l4->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(l4, 3, 0, 1, 1);
        QLabel *l5 = new QLabel("ЛК");
        l5->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:14px;"
        );
        l5->setAlignment(Qt::AlignRight);
        gridLayout->addWidget(l5, 3, 1, 1, 1);
        item->setLayout(gridLayout);

        itemHLayout->addWidget(item);

        mainVLayout->addLayout(itemHLayout);
    };

    this->setFixedWidth(296);
}
