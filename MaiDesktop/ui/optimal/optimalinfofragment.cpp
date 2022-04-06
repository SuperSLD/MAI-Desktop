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
#include <ui/optimal/items/infoblockwidget.h>

using namespace screens;
using namespace styles;


void OptimalInfoFragment::onBackPressed() {
    emit back();
}

OptimalInfoFragment::OptimalInfoFragment() {
    // Прокручивающийся контейнер
    QVBoxLayout *scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(25, 25, 25, 25);

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
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);
    scrolConttent->setLayout(mainHLayout);

    this->setLayout(scrollContainerLayout);  // назначение главного лейута

//    ScheduleModel *sch = dynamic_cast<ScheduleModel*>(model);
    QGridLayout *gridLayout = new QGridLayout;
    InfoBlockWidget *block1 = new InfoBlockWidget("80%", "Посещаемость", "#8773FF");
    gridLayout->addWidget(block1, 0, 0, 1, 1, Qt::AlignTop);
    InfoBlockWidget *block2 = new InfoBlockWidget("43", "Групп выбрано", COLOR_PRIMARY);
    gridLayout->addWidget(block2, 0, 1, 1, 1, Qt::AlignTop);
    InfoBlockWidget *block3 = new InfoBlockWidget("250", "Человек", "white");
    gridLayout->addWidget(block3, 0, 2, 1, 1, Qt::AlignTop);
    InfoBlockWidget *block4 = new InfoBlockWidget("1", "Удачные дни", COLOR_PRIMARY);
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
    QList<QString> *daysName = new QList<QString> {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб"};
    for (int i=0; i<6; i++) {
        ColumnWidget *column = new ColumnWidget((i+1)*10);
        columnsGridLayout->addWidget(column, 0, i, 1, 1, Qt::AlignTop);
        QLabel *dayColumnLabel = new QLabel(daysName->at(i));
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


//    // работаем с днями
//    QList <QString> dates;
//    for (int i=0; i<sch->getWeeks().size(); i++) {
//        for (int j=0; j<(sch->getWeeks()[i]).getDays().size(); j++) {
//            for (int k=0; k<sch->getWeeks()[i].getDays()[j].getSubjects().size(); k++) {
//                if (dates.indexOf(sch->getWeeks()[i].getDays()[j].getDate()) == -1 && sch->getWeeks()[i].getDays()[j].getSubjects()[k].getType() == "Экзамен") {
//                    DayScheduleWidget *day = new DayScheduleWidget(sch->getWeeks()[i].getDays()[j]);
//                    day->setFixedWidth(296);
//                    day->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
//                    gridLayout->addWidget(day, dates.size()/3, dates.size()%3, 1, 1, Qt::AlignTop);
//                    dates.append(sch->getWeeks()[i].getDays()[j].getDate());
//                };
//            };
//        };
//    };

}

//void OptimalInfoFragment::bindData(BaseModel* model) {

//}
