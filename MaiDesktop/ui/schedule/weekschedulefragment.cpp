#include "weekschedulefragment.h"

#include <QDebug>
#include <QGridLayout>
#include <QList>
#include <QScrollArea>
#include <QScrollBar>

#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/swgbutton.h>
#include <ui/widgets/toolbarwidget.h>
#include <ui/schedule/items/dayschedulewidget.h>
#include <data/models/schedule/schedulemodel.h>

using namespace screens;
using namespace styles;

WeekScheduleFragment::WeekScheduleFragment() {

};

void WeekScheduleFragment::onBackPressed() {
    emit back();
};

void WeekScheduleFragment::onButtinPressed() {
    emit replaceWhithData(SELECT_WEEK, this->mainModel);
};

void WeekScheduleFragment::bindData(BaseModel* model) {
    this->mainModel = model;
    ScheduleModel *sch = dynamic_cast<ScheduleModel*>(model);

    // Прокручивающийся контейнер
    QVBoxLayout *scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(25, 25, 25, 25);

    QHBoxLayout *ContainerHLayout = new QHBoxLayout; // выравнивание по горизонтали

    // Находим и сохраняем в переменную currentWeekNumber номер текущей недели
    for (int i=0; i<sch->getWeeks().size(); i++) {
        if (QDate::currentDate() >= QDate::fromString(sch->getWeeks()[i].getDate().mid(0, 10), Qt::LocaleDate) && QDate::currentDate() <= QDate::fromString(sch->getWeeks()[i].getDate().mid(13, 10), Qt::LocaleDate)) {
            this->currentWeekNumber = sch->getWeeks()[i].getNumber();
            break;
        };
    };

    // Работаем с тулбаром
    ToolbarWidget *toolbar = new ToolbarWidget("Неделя "+QString::number(this->currentWeekNumber) + " (Текущая)", true, "selectweek");
    toolbar->setFixedHeight(71);
    toolbar->setFixedWidth(952);
    // При нажатии на кнопку "Выбор недели" переходим к одноимённому экрану
    connect(toolbar, &ToolbarWidget::onButtinPressed, this, &WeekScheduleFragment::onButtinPressed);    // слот-сигнал
    // При нажатии на стрелочку переходим к предыдущему экрану
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &WeekScheduleFragment::onBackPressed);    // слот-сигнал
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
    for (int i=0; i<sch->getWeeks()[this->currentWeekNumber-1].getDays().size(); i++) {
        DayScheduleWidget *day = new DayScheduleWidget(sch->getWeeks()[this->currentWeekNumber-1].getDays()[i]);
        day->setFixedWidth(296);
        day->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        gridLayout->addWidget(day, i/3, i%3, 1, 1, Qt::AlignTop);
    };
    gridLayout->setHorizontalSpacing(32);   // расстояние между столбцами
    gridLayout->setVerticalSpacing(32);   // расстояние между строками
    mainVLayout->addLayout(gridLayout);
}
