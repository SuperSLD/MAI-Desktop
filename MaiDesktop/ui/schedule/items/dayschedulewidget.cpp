#include "dayschedulewidget.h"

#include <QFont>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>

#include <stylecontainer.h>
#include <ui/widgets/swgbutton.h>

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
    QLabel *dateLabel = new QLabel(dayInfo.getDate().remove(5, 11));
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
        QLabel *nameLabel = new QLabel(dayInfo.getSubjects()[i].getName());
        nameLabel->setFixedHeight(25*((fontMetrics().boundingRect(dayInfo.getSubjects()[i].getName()).width()/138)+1));  // высота nameLabel задаётся по содержимому тексту
        nameLabel->setFont(QFont("Roboto", 18));
        QHBoxLayout *nameLabelHLayout = new QHBoxLayout;
        nameLabelHLayout->setContentsMargins(0, 0, 0, 8);
        nameLabel->setStyleSheet(
            "color: white;"
        );
        nameLabel->setAlignment(Qt::AlignLeft);
        nameLabel->setWordWrap(true);
        nameLabelHLayout->addWidget(nameLabel);
        gridLayout->addLayout(nameLabelHLayout, 0, 0, 1, 2);
        QLabel *lectorLabel = new QLabel(dayInfo.getSubjects()[i].getLector().getName());
        lectorLabel->setFont(QFont("Roboto", 14));
        lectorLabel->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
        );
        lectorLabel->setAlignment(Qt::AlignLeft);
        lectorLabel->setWordWrap(true);
        gridLayout->addWidget(lectorLabel, 1, 0, 1, 2);
        QLabel *timeLabel = new QLabel(dayInfo.getSubjects()[i].getTimeStart() + " - " + dayInfo.getSubjects()[i].getTimeEnd());
        timeLabel->setFont(QFont("Roboto", 14));
        QHBoxLayout *timeLabelHLayout = new QHBoxLayout;
        timeLabelHLayout->setContentsMargins(0, 0, 0, 8);
        timeLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        timeLabel->setAlignment(Qt::AlignLeft);
        timeLabelHLayout->addWidget(timeLabel);
        gridLayout->addLayout(timeLabelHLayout, 2, 0, 1, 2);
        QLabel *roomLabel = new QLabel(dayInfo.getSubjects()[i].getRoom().getName());
        roomLabel->setFont(QFont("Roboto", 14));
        roomLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        roomLabel->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(roomLabel, 3, 0, 1, 1);
        QLabel *subjectLabel = new QLabel(dayInfo.getSubjects()[i].getType());
        subjectLabel->setFont(QFont("Roboto", 14));
        subjectLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        subjectLabel->setAlignment(Qt::AlignRight);
        gridLayout->addWidget(subjectLabel, 3, 1, 1, 1);
        QLabel *breakLine = new QLabel();
        QHBoxLayout *breakLineHLayout = new QHBoxLayout;
        breakLineHLayout->setContentsMargins(0, 14, 0, 0);
        breakLine->setFixedHeight(1);
        breakLine->setStyleSheet(
            "background-color:" + COLOR_BORDER + ";"
        );
        breakLine->setAlignment(Qt::AlignHCenter);
        breakLineHLayout->addWidget(breakLine);
        gridLayout->addLayout(breakLineHLayout, 4, 0, 1, 2);

        if (dayInfo.getSubjects()[i].getTimeEnd() == "12:15") {
            QHBoxLayout *dinnerContainer = new QHBoxLayout;
            SwgButton *dinnerButton = new SwgButton(":/resc/resc/dinner.svg", QSize(24,24));
            QLabel *dinnerLabel = new QLabel("Обеденный перерыв");
            dinnerLabel->setFont(QFont("Roboto", 14));
            dinnerLabel->setStyleSheet(
                "color:" + COLOR_TEXT_SECONDARY + ";"
            );
            dinnerContainer->addWidget(dinnerButton);
            dinnerContainer->addWidget(dinnerLabel);
            dinnerContainer->setContentsMargins(0,14,0,0);
            //dinnerLabel->setContentsMargins(0,0,0,0);
            gridLayout->addLayout(dinnerContainer, 5, 0, 1, 2);

            QLabel *breakLineDinner = new QLabel();
            QHBoxLayout *breakLineDinnerHLayout = new QHBoxLayout;
            breakLineDinnerHLayout->setContentsMargins(0, 14, 0, 0);
            breakLineDinner->setFixedHeight(1);
            breakLineDinner->setStyleSheet(
                "background-color:" + COLOR_BORDER + ";"
            );
            breakLineDinner->setAlignment(Qt::AlignHCenter);
            breakLineDinnerHLayout->addWidget(breakLineDinner);
            gridLayout->addLayout(breakLineDinnerHLayout, 6, 0, 1, 2);
        };

        rightArea->setLayout(gridLayout);

        if (QDate::currentDate().toString("dd.MM.yyyy") == this->date && QTime::currentTime() >= QTime::fromString(dayInfo.getSubjects()[i].getTimeStart(), "HH:mm") && QTime::currentTime() <= QTime::fromString(dayInfo.getSubjects()[i].getTimeEnd(), "HH:mm")) {
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
