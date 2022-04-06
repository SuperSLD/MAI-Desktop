#include "dayinfowidget.h"

#include <QFont>
#include <QBoxLayout>
#include <QLabel>
#include <QTime>

#include <stylecontainer.h>
#include <ui/widgets/swgbutton.h>

using namespace styles;

DayInfoWidget::DayInfoWidget(QString dayName, QList<QString> dayTimes, QList<QString> dayPercent, QList<QString> dayCountPeople) {

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainVLayout->setSpacing(0);
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);  // назначение главного лейута

    QLabel *dayNameLabel = new QLabel(dayName);
    dayNameLabel->setFont(QFont("Roboto", 24, QFont::Bold));
    QHBoxLayout *dateHLayout = new QHBoxLayout;
    dateHLayout->setAlignment(Qt::AlignLeft);
    dateHLayout->setContentsMargins(0, 0, 0, 10);
    dateHLayout->setSpacing(10);
    dayNameLabel->setStyleSheet(
        "color: white;"
    );
    dayNameLabel->setAlignment(Qt::AlignBottom);
    dateHLayout->addWidget(dayNameLabel);

    for (int i=0; i<dayTimes.size(); i++) {
        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->setMargin(0);
        //gridLayout->setHorizontalSpacing(4);
        QLabel *nameLabel = new QLabel(dayTimes.at(i));
        nameLabel->setFont(QFont("Roboto", 18));
        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        QLabel *dpLabel = new QLabel("Процент посещения");
        dpLabel->setFont(QFont("Roboto", 18));
        dpLabel->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
        );
        dpLabel->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(dpLabel, 0, 1, 1, 1);

        QLabel *dayPercentLabel = new QLabel(dayPercent.at(i));
        dayPercentLabel->setFont(QFont("Roboto", 18));
        dayPercentLabel->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
        );
        dayPercentLabel->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(dayPercentLabel, 0, 2, 1, 1);

        QLabel *dcpLabel = new QLabel("Количество человек");
        dcpLabel->setFont(QFont("Roboto", 18));
        dcpLabel->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(dcpLabel, 0, 3, 1, 1);

        QLabel *dayCountPeopleLabel = new QLabel(dayCountPeople.at(i));
        dayCountPeopleLabel->setFont(QFont("Roboto", 18));
        dayCountPeopleLabel->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(dayCountPeopleLabel, 0, 4, 1, 1);


        if (dayTimes.size() == 0) {

        };

        mainVLayout->addLayout(gridLayout);
    };
}

