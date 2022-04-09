#include "optimalinfofragment.h"

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QScrollArea>
#include <QScrollBar>

#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/toolbarwidget.h>
#include <ui/optimal/items/columnwidget.h>
#include <ui/optimal/items/dayinfowidget.h>
#include <ui/optimal/items/infoblockwidget.h>
#include <data/models/group/grouplist.h>

using namespace screens;
using namespace styles;


void OptimalInfoFragment::onBackPressed() {
    emit back();
}

OptimalInfoFragment::OptimalInfoFragment() {

}

void OptimalInfoFragment::listenOptimalTime(DataWrapper<OptimalModel> wrapper) {
    if (wrapper.isSuccess()) {
        loadingContainer->stopLoading();
        optimalTime = wrapper.getData();

        // Находим кол-во "Удачных дней"
        int countLuckyDays = 0;
        int countTimeCheck = 0;
        qDebug() << optimalTime.getWeekDataList().size();
        for (int i=0; i<6; i++) {
            countTimeCheck = 0;
            for (int j=0; j<optimalTime.getWeekDataList()[i].getTimeData().size(); j++) {
                if (optimalTime.getWeekDataList()[i].getTimeData()[j].getIntTime() < 1020) {
                    countTimeCheck++;
                };
            };
            if (countTimeCheck == optimalTime.getWeekDataList()[i].getTimeData().size()) {
                countLuckyDays++;
            }
        };

        QGridLayout *gridLayout = new QGridLayout;
        InfoBlockWidget *block1 = new InfoBlockWidget(QString::number(optimalTime.getMinPercent()) + "%", "Посещаемость", "#8773FF");
        gridLayout->addWidget(block1, 0, 0, 1, 1, Qt::AlignTop);
        InfoBlockWidget *block2 = new InfoBlockWidget(QString::number(optimalTime.getGroupsCount()), "Групп выбрано", COLOR_PRIMARY);
        gridLayout->addWidget(block2, 0, 1, 1, 1, Qt::AlignTop);
        InfoBlockWidget *block3 = new InfoBlockWidget(QString::number(optimalTime.getTotal()), "Человек", "white");
        gridLayout->addWidget(block3, 0, 2, 1, 1, Qt::AlignTop);
        InfoBlockWidget *block4 = new InfoBlockWidget(QString::number(countLuckyDays), "Удачные дни", COLOR_PRIMARY);
        gridLayout->addWidget(block4, 0, 3, 1, 1, Qt::AlignTop);
        gridLayout->setHorizontalSpacing(23);   // расстояние между столбцами
        mainVLayout->addLayout(gridLayout);

        QLabel *breakLine = new QLabel();
        QHBoxLayout *breakLineHLayout = new QHBoxLayout;
        breakLineHLayout->setContentsMargins(0, 24, 0, 12);
        breakLine->setFixedHeight(1);
        breakLine->setStyleSheet(
            "background-color:" + COLOR_BORDER + ";"
        );
        breakLine->setAlignment(Qt::AlignHCenter);
        breakLineHLayout->addWidget(breakLine);
        mainVLayout->addLayout(breakLineHLayout);

        QGridLayout *columnsGridLayout = new QGridLayout;
        for (int i=0; i<6; i++) {
            double allPercent = 0;
            for (int j=0; j<optimalTime.getWeekDataList()[i].getTimeData().size(); j++) {
                allPercent += optimalTime.getWeekDataList()[i].getTimeData()[j].getPercent();
            }
            ColumnWidget *column = new ColumnWidget(allPercent/optimalTime.getWeekDataList()[i].getTimeData().size());
            columnsGridLayout->addWidget(column, 0, i, 1, 1, Qt::AlignTop);
            QLabel *dayColumnLabel = new QLabel(optimalTime.getWeekDataList()[i].getName());
            dayColumnLabel->setFont(QFont("Roboto", 24));
            dayColumnLabel->setStyleSheet(
                "color: white;"
            );
            dayColumnLabel->setAlignment(Qt::AlignHCenter);
            columnsGridLayout->addWidget(dayColumnLabel, 1, i, 1, 1, Qt::AlignTop);
        };
        gridLayout->setHorizontalSpacing(14);   // расстояние между столбцами
        mainVLayout->addLayout(columnsGridLayout);

        QLabel *breakLine2 = new QLabel();
        QHBoxLayout *breakLine2HLayout = new QHBoxLayout;
        breakLine2HLayout->setContentsMargins(0, 24, 0, 12);
        breakLine2->setFixedHeight(1);
        breakLine2->setStyleSheet(
            "background-color:" + COLOR_BORDER + ";"
        );
        breakLine2->setAlignment(Qt::AlignHCenter);
        breakLine2HLayout->addWidget(breakLine2);
        mainVLayout->addLayout(breakLine2HLayout);

        for (int i=0; i<6; i++) {
            DayInfoWidget *dayInfo = new DayInfoWidget(&optimalTime.getWeekDataList()[i]);
            mainVLayout->addWidget(dayInfo);
        };

    } else {
        loadingContainer->error(wrapper.getMessage());
    }
}

void OptimalInfoFragment::bindData(BaseModel* model) {

    // подключение репозитория
    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenOptimalTime, this, &OptimalInfoFragment::listenOptimalTime);

    // главный контейнер
    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->setLayout(mainLayout);

    // Прокручивающийся контейнер
    QFrame *mainFrame = new QFrame;
    QVBoxLayout *scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(25, 25, 25, 25);
    mainFrame->setLayout(scrollContainerLayout);  // назначение главного лейута

    QHBoxLayout *ContainerHLayout = new QHBoxLayout; // выравнивание по горизонтали

    // Работаем с тулбаром
    ToolbarWidget *toolbar = new ToolbarWidget("Результат поиска", true);
    toolbar->setFixedHeight(71);
    toolbar->setFixedWidth(952);
    // При нажатии на стрелочку переходим к предыдущему экрану
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &OptimalInfoFragment::onBackPressed);  // слот-сигнал
    ContainerHLayout->addWidget(toolbar);

    scrollContainerLayout->addLayout(ContainerHLayout);

    // Зона прокрутки
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setStyleSheet("background-color:#FF7777;");
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setMinimumSize(QSize(200, 200));
    QWidget *scrolConttent = new QWidget;
    scrolConttent->setObjectName("container");
    scrollArea->setStyleSheet(SCROL_BAR);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrolConttent);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->verticalScrollBar()->hide();
    scrollContainerLayout->addWidget(scrollArea);

    // Основное расположение элементов в окне
    mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);
    scrolConttent->setLayout(mainHLayout);


    GroupList *group_list = dynamic_cast<GroupList*>(model);

    // контейнер загрузки
    loadingContainer = new LoadingContainerWidget(mainFrame);
    loadingContainer->startLoading("Загружаем оптимальное время...");
    mainLayout->addWidget(loadingContainer);
    netRep->getOptimalTime(*group_list);
}
