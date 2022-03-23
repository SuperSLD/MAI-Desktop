#include "dayschedulewidget.h"

#include <QFont>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>

#include <stylecontainer.h>

using namespace styles;

DayScheduleWidget::DayScheduleWidget(DayModel dayInfo) {

    this->date = dayInfo.getDate();
    this->name = dayInfo.getName();

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainVLayout->setSpacing(0);
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);  // назначение главного лейута

    QLabel *dayWeeekLabel = new QLabel(this->name);
    dayWeeekLabel->setFont(QFont("Roboto", 24, QFont::Bold));
    QHBoxLayout *dateHLayout = new QHBoxLayout;
    dateHLayout->setAlignment(Qt::AlignLeft);
    dateHLayout->setContentsMargins(0, 0, 0, 10);
    dateHLayout->setSpacing(10);
    dayWeeekLabel->setStyleSheet(
        "color: white;"
    );
    dayWeeekLabel->setAlignment(Qt::AlignBottom);
    dateHLayout->addWidget(dayWeeekLabel);
    QLabel *dateLabel = new QLabel(this->date.remove(5, 11));
    dateLabel->setFont(QFont("Roboto", 14, QFont::Bold));
    dateLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
    );
    dateLabel->setAlignment(Qt::AlignBottom);
    dateHLayout->addWidget(dateLabel);
    mainVLayout->addLayout(dateHLayout);

    for (int i=0; i<dayInfo.getSubjects().size(); i++) {
        QHBoxLayout *itemHLayout = new QHBoxLayout;
        itemHLayout->setSpacing(13);    // расстояние между правой и левой областями

        QFrame *leftArea = new QFrame;
        QVBoxLayout *leftAreaVLayout = new QVBoxLayout;
        leftAreaVLayout->setMargin(0);
        leftAreaVLayout->setSpacing(0);
        leftArea->setFixedWidth(24);
        QLabel *countLabel = new QLabel(dayInfo.getSubjects()[i].getNumber());
        countLabel->setFont(QFont("Roboto", 18, QFont::Bold));
        countLabel->setFixedWidth(24);
        countLabel->setFixedHeight(24);
        countLabel->setAlignment(Qt::AlignHCenter);
        leftAreaVLayout->addWidget(countLabel);
        QFrame *line = new QFrame;
        QHBoxLayout *lineHLayout = new QHBoxLayout;
        lineHLayout->setAlignment(Qt::AlignHCenter);
        lineHLayout->addWidget(line);
        line->setFixedWidth(4);

        leftAreaVLayout->addLayout(lineHLayout);

        leftArea->setLayout(leftAreaVLayout);

        itemHLayout->addWidget(leftArea);

        QFrame *rightArea = new QFrame;
        rightArea->setFixedWidth(223);
        rightArea->setContentsMargins(0, 0, 0, 20); // нижний отступ у правой части

        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->setMargin(0);
        gridLayout->setVerticalSpacing(4);
        QLabel *l1 = new QLabel(dayInfo.getSubjects()[i].getName());
        l1->setFont(QFont("Roboto", 18));
        QHBoxLayout *l1HLayout = new QHBoxLayout;
        l1HLayout->setContentsMargins(0, 0, 0, 8);
        l1->setStyleSheet(
            "color: white;"
        );
        l1->setAlignment(Qt::AlignLeft);
        l1->setWordWrap(true);
        l1HLayout->addWidget(l1);
        gridLayout->addLayout(l1HLayout, 0, 0, 1, 2);
        QLabel *l2 = new QLabel(dayInfo.getSubjects()[i].getLector().getName());
        l2->setFont(QFont("Roboto", 14));
        l2->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
        );
        l2->setAlignment(Qt::AlignLeft);
        l2->setWordWrap(true);
        gridLayout->addWidget(l2, 1, 0, 1, 2);
        QLabel *l3 = new QLabel(dayInfo.getSubjects()[i].getTimeStart() + " - " + dayInfo.getSubjects()[i].getTimeEnd());
        l3->setFont(QFont("Roboto", 14));
        QHBoxLayout *l3HLayout = new QHBoxLayout;
        l3HLayout->setContentsMargins(0, 0, 0, 8);
        l3->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        l3->setAlignment(Qt::AlignLeft);
        l3HLayout->addWidget(l3);
        gridLayout->addLayout(l3HLayout, 2, 0, 1, 2);
        QLabel *l4 = new QLabel(dayInfo.getSubjects()[i].getRoom().getName());
        l4->setFont(QFont("Roboto", 14));
        l4->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        l4->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(l4, 3, 0, 1, 1);
        QLabel *l5 = new QLabel(dayInfo.getSubjects()[i].getType());
        l5->setFont(QFont("Roboto", 14));
        l5->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
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

        if (QDateTime::currentDateTime().toString("dd.MM.yyyy") == this->date && (QTime::currentTime().toString("HHmm").toInt()+1000 > dayInfo.getSubjects()[i].getTimeStart().replace(":", "") && QTime::currentTime().toString("HHmm").toInt()+1000 < dayInfo.getSubjects()[i].getTimeEnd().replace(":", ""))) {
            line->setStyleSheet(
                "background-color:"+COLOR_PRIMARY+";"
            );
            countLabel->setStyleSheet(
                "color: white;"
                "border-radius: 12px;"
                "background-color:"+COLOR_PRIMARY+";"
            );
        } else {
            line->setStyleSheet(
                "background-color:"+COLOR_BORDER+";"
            );
            countLabel->setStyleSheet(
                "color: white;"
                "border-radius: 12px;"
                "background-color:"+COLOR_BORDER+";"
            );
        };

        itemHLayout->addWidget(rightArea);

        mainVLayout->addLayout(itemHLayout);
    };
}
