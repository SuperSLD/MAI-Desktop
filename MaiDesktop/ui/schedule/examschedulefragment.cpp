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

}

void ExamScheduleFragment::onBackPressed() {
    emit back();
}

void ExamScheduleFragment::bindData(BaseModel* model) {
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

    ScheduleModel *sch = dynamic_cast<ScheduleModel*>(model);
    QGridLayout *gridLayout = new QGridLayout;
    // работаем с днями
    QList <QString> dates;
    for (int i=0; i<sch->getWeeks().size(); i++) {
        for (int j=0; j<(sch->getWeeks()[i]).getDays().size(); j++) {
            for (int k=0; k<sch->getWeeks()[i].getDays()[j].getSubjects().size(); k++) {
                if (dates.indexOf(sch->getWeeks()[i].getDays()[j].getDate()) == -1 && sch->getWeeks()[i].getDays()[j].getSubjects()[k].getType() == "Экзамен") {
                    DayScheduleWidget *day = new DayScheduleWidget(sch->getWeeks()[i].getDays()[j]);
                    day->setFixedWidth(296);
                    day->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
                    gridLayout->addWidget(day, dates.size()/3, dates.size()%3, 1, 1, Qt::AlignTop);
                    dates.append(sch->getWeeks()[i].getDays()[j].getDate());
                };
            };
        };
    };
    gridLayout->setHorizontalSpacing(32);   // расстояние между столбцами
    gridLayout->setVerticalSpacing(32);   // расстояние между строками
    mainVLayout->addLayout(gridLayout);
}
