#include "dayinfowidget.h"

#include <QFont>
#include <QBoxLayout>
#include <QLabel>
#include <QTime>

#include <stylecontainer.h>
#include <ui/widgets/swgbutton.h>

using namespace styles;

DayInfoWidget::DayInfoWidget(OptimalDayModel *dayInfo) {

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignLeft); // направление выравнивания (к центру)
    mainVLayout->setSpacing(0);
    mainVLayout->setMargin(15);
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);  // назначение главного лейута

    QLabel *dayNameLabel = new QLabel(dayInfo->getName());
    dayNameLabel->setFont(QFont("Roboto", 24, QFont::Bold));
    QHBoxLayout *dayNameHLayout = new QHBoxLayout;
    dayNameHLayout->setAlignment(Qt::AlignLeft);
    dayNameHLayout->setContentsMargins(0, 0, 0, 0);
    dayNameHLayout->setSpacing(10);
    dayNameLabel->setStyleSheet(
        "color: white;"
    );
    dayNameLabel->setAlignment(Qt::AlignBottom);
    dayNameHLayout->addWidget(dayNameLabel);
    mainVLayout->addLayout(dayNameHLayout);

    for (int i=0; i<dayInfo->getTimeData().size(); i++) {
        QLabel *breakLine = new QLabel();
        QHBoxLayout *breakLineHLayout = new QHBoxLayout;
        breakLineHLayout->setContentsMargins(0, 12, 0, 12);
        breakLine->setFixedHeight(1);
        breakLine->setStyleSheet(
            "background-color:" + COLOR_BORDER + ";"
        );
        breakLine->setAlignment(Qt::AlignHCenter);
        breakLineHLayout->addWidget(breakLine);
        mainVLayout->addLayout(breakLineHLayout);

        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->setMargin(0);
        gridLayout->setHorizontalSpacing(180);
        QLabel *nameLabel = new QLabel(dayInfo->getTimeData()[i].getTime());
        nameLabel->setFont(QFont("Roboto", 18));
        nameLabel->setStyleSheet(
            "color:white;"
        );
        nameLabel->setAlignment(Qt::AlignLeft);
        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        QHBoxLayout *dayPercentHLayout = new QHBoxLayout;
        dayPercentHLayout->setContentsMargins(0, 0, 0, 0);
        QLabel *dpLabel = new QLabel("Процент посещения");
        dpLabel->setFont(QFont("Roboto", 18));
        dpLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        //dpLabel->setAlignment(Qt::AlignLeft);
        dayPercentHLayout->addWidget(dpLabel);
        QLabel *dayPercentLabel = new QLabel(QString::number(dayInfo->getTimeData()[i].getPercent()));
        dayPercentLabel->setFont(QFont("Roboto", 18));
        dayPercentLabel->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
        );
        //dayPercentLabel->setAlignment(Qt::AlignLeft);
        dayPercentHLayout->addWidget(dayPercentLabel);
        gridLayout->addLayout(dayPercentHLayout, 0, 1, 1, 2);

        QHBoxLayout *dayCountPeopleHLayout = new QHBoxLayout;
        dayCountPeopleHLayout->setContentsMargins(0, 0, 0, 0);
        QLabel *dcpLabel = new QLabel("Количество человек");
        dcpLabel->setFont(QFont("Roboto", 18));
        dcpLabel->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
        );
        //dcpLabel->setAlignment(Qt::AlignRight);
        dayCountPeopleHLayout->addWidget(dcpLabel);
        QLabel *dayCountPeopleLabel = new QLabel(QString::number(dayInfo->getTimeData()[i].getCount()));
        dayCountPeopleLabel->setFont(QFont("Roboto", 18));
        dayCountPeopleLabel->setStyleSheet(
            "color:" + COLOR_PRIMARY + ";"
        );
        //dayCountPeopleLabel->setAlignment(Qt::AlignRight);
        dayCountPeopleHLayout->addWidget(dayCountPeopleLabel);
        gridLayout->addLayout(dayCountPeopleHLayout, 0, 3, 1, 2);


        if (dayInfo->getTimeData().size() == 0) {
            qDebug() << "dayInfo->getTimeData().size() == 0";
        };
        mainVLayout->addLayout(gridLayout);
    };
}

