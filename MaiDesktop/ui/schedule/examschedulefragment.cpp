#include "examschedulefragment.h"

#include <QDebug>
#include <QGridLayout>
#include <QList>
#include <QScrollArea>
#include <QScrollBar>

#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/toolbarwidget.h>
#include <ui/schedule/items/dayschedulewidget.h>
#include <data/models/schedule/schedulemodel.h>

using namespace screens;
using namespace styles;

ExamScheduleFragment::ExamScheduleFragment() {
    // Прокручивающийся контейнер
    QVBoxLayout *scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(25, 25, 25, 25);

    QHBoxLayout *ContainerHLayout = new QHBoxLayout; // выравнивание по горизонтали

    // Работаем с тулбаром
    ToolbarWidget *toolbar = new ToolbarWidget("Расписание экзаменов", true);
    toolbar->setFixedHeight(71);
    toolbar->setFixedWidth(952);
    // При нажатии на стрелочку переходим к предыдущему экрану
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &ExamScheduleFragment::onBackPressed);  // слот-сигнал
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

    QGridLayout *gridLayout = new QGridLayout;
    // работаем с днями
    DayScheduleWidget *day_1 = new DayScheduleWidget(3);
    day_1->setFixedWidth(296);
    gridLayout->addWidget(day_1, 0, 0, 1, 1);
    DayScheduleWidget *day_2 = new DayScheduleWidget(2);
    day_2->setFixedWidth(296);
    gridLayout->addWidget(day_2, 0, 1, 1, 1);
    DayScheduleWidget *day_3 = new DayScheduleWidget(1);
    day_3->setFixedWidth(296);
    gridLayout->addWidget(day_3, 0, 2, 1, 1);
    DayScheduleWidget *day_4 = new DayScheduleWidget(3);
    day_4->setFixedWidth(296);
    gridLayout->addWidget(day_4, 1, 0, 1, 1);
    DayScheduleWidget *day_5 = new DayScheduleWidget(2);
    day_5->setFixedWidth(296);
    gridLayout->addWidget(day_5, 1, 1, 1, 1);
    DayScheduleWidget *day_6 = new DayScheduleWidget(1);
    day_6->setFixedWidth(296);
    gridLayout->addWidget(day_6, 1, 2, 1, 1);

    gridLayout->setHorizontalSpacing(32);   // расстояние между столбцами
    gridLayout->setVerticalSpacing(32);   // расстояние между строками
    mainVLayout->addLayout(gridLayout);
}

void ExamScheduleFragment::onBackPressed() {
    emit back();
}

void ExamScheduleFragment::bindData(BaseModel* model) {
    ScheduleModel *sch = dynamic_cast<ScheduleModel*>(model);
    for (int i=0; i<sch->getWeeks().size(); i++) {
        for (int j=0; j<(sch->getWeeks()[i]).getDays().size(); j++) {
            qDebug() << 1;
            //qDebug() << sch->getWeeks()[i].getDays()[j].getId();
//            for (int k=0; k<sch->getWeeks()[i].getDays()[j].getSubjects().size(); k++) {
//                qDebug() << sch->getWeeks()[i].getDays()[j].getSubjects()[k].getId();
////                if (sch->getWeeks()[i].getDays()[j].getSubjects()[k].getType() == QString("ПЗ")) {
////                    qDebug() << sch->getWeeks()[i].getDays()[j].getSubjects()[k].getType() << " " << sch->getWeeks()[i].getDays()[j].getSubjects()[k].getName();
////                };
//            };
        }
    }
}

