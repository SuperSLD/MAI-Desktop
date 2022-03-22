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
    mainVLayout->setSpacing(0);
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);  // назначение главного лейута

    QLabel *dayWeeekLabel = new QLabel("Пн");
    QHBoxLayout *dateHLayout = new QHBoxLayout;
    dateHLayout->setAlignment(Qt::AlignLeft);
    dateHLayout->setContentsMargins(0, 0, 0, 10);
    dateHLayout->setSpacing(10);
    dayWeeekLabel->setStyleSheet(
        "color: white;"
        "font-size: 24px;"
        "font-weight: bold;"
    );
    dayWeeekLabel->setAlignment(Qt::AlignBottom);
    dateHLayout->addWidget(dayWeeekLabel);
    QLabel *dateLabel = new QLabel("24.05");
    dateLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size: 14px;"
        "font-weight: bold;"
    );
    dateLabel->setAlignment(Qt::AlignBottom);
    dateHLayout->addWidget(dateLabel);
    mainVLayout->addLayout(dateHLayout);

    for (int i=0; i<countItems; i++) {
        QHBoxLayout *itemHLayout = new QHBoxLayout;
        itemHLayout->setSpacing(13);    // расстояние между правой и левой областями

        QFrame *leftArea = new QFrame;
        QVBoxLayout *leftAreaVLayout = new QVBoxLayout;
        leftAreaVLayout->setMargin(0);
        leftAreaVLayout->setSpacing(0);
        leftArea->setFixedWidth(24);
        //leftArea->setStyleSheet("background-color: black;");
        QLabel *countLabel = new QLabel(QString::number(i+1));
        countLabel->setFixedWidth(24);
        countLabel->setFixedHeight(24);
        countLabel->setStyleSheet(
            "color: white;"
            "font-size: 18px;"
            "font-weight: bold;"
            "border-radius: 12px;"
            "background-color:"+COLOR_PRIMARY+";"
        );
        countLabel->setAlignment(Qt::AlignHCenter);
        leftAreaVLayout->addWidget(countLabel);
        QFrame *line = new QFrame;
        QHBoxLayout *lineHLayout = new QHBoxLayout;
        lineHLayout->setAlignment(Qt::AlignHCenter);
        lineHLayout->addWidget(line);
        line->setFixedWidth(4);
        line->setStyleSheet(
            "background-color:"+COLOR_PRIMARY+";"
        );
        leftAreaVLayout->addLayout(lineHLayout);

        leftArea->setLayout(leftAreaVLayout);

        itemHLayout->addWidget(leftArea);

        QFrame *rightArea = new QFrame;
        rightArea->setFixedWidth(223);
        rightArea->setContentsMargins(0, 0, 0, 20); // нижний отступ у правой части

        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->setMargin(0);
        gridLayout->setVerticalSpacing(4);
        QLabel *l1 = new QLabel("Технология системного моделирования");
        QHBoxLayout *l1HLayout = new QHBoxLayout;
        l1HLayout->setContentsMargins(0, 0, 0, 8);
        l1->setStyleSheet(
            "color: white;"
            "font-size:18px;"
        );
        l1->setAlignment(Qt::AlignLeft);
        l1->setWordWrap(true);
        l1HLayout->addWidget(l1);
        gridLayout->addLayout(l1HLayout, 0, 0, 1, 2);
        QLabel *l2 = new QLabel("Топорова Мария Илларионова");
        l2->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
            "font-size:14px;"
        );
        l2->setAlignment(Qt::AlignLeft);
        l2->setWordWrap(true);
        gridLayout->addWidget(l2, 1, 0, 1, 2);
        QLabel *l3 = new QLabel("09:00 - 10:30");
        QHBoxLayout *l3HLayout = new QHBoxLayout;
        l3HLayout->setContentsMargins(0, 0, 0, 8);
        l3->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:14px;"
        );
        l3->setAlignment(Qt::AlignLeft);
        l3HLayout->addWidget(l3);
        gridLayout->addLayout(l3HLayout, 2, 0, 1, 2);
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
        QLabel *breakLine = new QLabel();
        QHBoxLayout *breakLineHLayout = new QHBoxLayout;
        breakLineHLayout->setContentsMargins(0, 10, 0, 0);
        breakLine->setFixedHeight(1);
        breakLine->setStyleSheet(
            "background-color:" + COLOR_BORDER + ";"
        );
        breakLine->setAlignment(Qt::AlignHCenter);
        breakLineHLayout->addWidget(breakLine);
        gridLayout->addLayout(breakLineHLayout, 4, 0, 1, 2);
        rightArea->setLayout(gridLayout);

        itemHLayout->addWidget(rightArea);

        mainVLayout->addLayout(itemHLayout);
    };
}
