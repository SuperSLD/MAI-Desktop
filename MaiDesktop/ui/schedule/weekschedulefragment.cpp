#include "weekschedulefragment.h"

#include <QDebug>
#include <QGridLayout>
#include <QList>
#include <QScrollArea>
#include <QScrollBar>

#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/swgbutton.h>
#include <ui/schedule/items/dayschedulewidget.h>


using namespace screens;
using namespace styles;

WeekScheduleFragment::WeekScheduleFragment() {

};

void WeekScheduleFragment::onBackPressed() {
    this->sch->setCurrentWeekNumber(-1);
    emit back();
};

void WeekScheduleFragment::onButtinPressed() {
    if (this->currentWeekNumber == 0) {
        this->sch->setCurrentWeekNumber(this->nowWeekNumber);
        emit replaceWhithData(SELECT_WEEK, this->sch);
    } else {
        this->sch->setCurrentWeekNumber(this->currentWeekNumber);
        emit replaceWhithData(SELECT_WEEK, this->sch);
    };
};

void WeekScheduleFragment::bindData(BaseModel* model) {
    this->sch = dynamic_cast<ScheduleModel*>(model);

    // Прокручивающийся контейнер
    QVBoxLayout *scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(25, 25, 25, 25);

    QHBoxLayout *ContainerHLayout = new QHBoxLayout; // выравнивание по горизонтали

    // Находим и сохраняем в переменную nowWeekNumber номер текущей недели и в переменную currentWeekNumber номер выбранной недели
    for (int i=0; i<this->sch->getWeeks().size(); i++) {
        if (QDate::currentDate() >= QDate::fromString(this->sch->getWeeks()[i].getDate().mid(0, 10), Qt::LocaleDate) && QDate::currentDate() <= QDate::fromString(this->sch->getWeeks()[i].getDate().mid(13, 10), Qt::LocaleDate)) {
            this->nowWeekNumber = this->sch->getWeeks()[i].getNumber();
        };
        if (this->sch->getCurrentWeekNumber() != -1) {
            this->currentWeekNumber = this->sch->getCurrentWeekNumber();
        };
    };

    // Работаем с тулбаром
    if (this->currentWeekNumber == 0) {
        toolbar = new ToolbarWidget("Неделя "+QString::number(this->nowWeekNumber) + " (Текущая)", true, "selectweek");
    } else {
        toolbar = new ToolbarWidget("Неделя "+QString::number(this->currentWeekNumber), true, "selectweek");
    };
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
    if (this->currentWeekNumber == 0) {
        for (int i=0; i<this->sch->getWeeks()[this->nowWeekNumber-1].getDays().size(); i++) {
            DayScheduleWidget *day = new DayScheduleWidget(this->sch->getWeeks()[this->nowWeekNumber-1].getDays()[i]);
            day->setFixedWidth(296);
            day->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
            gridLayout->addWidget(day, i/3, i%3, 1, 1, Qt::AlignTop);
        };
    } else {
        for (int i=0; i<this->sch->getWeeks()[this->currentWeekNumber-1].getDays().size(); i++) {
            DayScheduleWidget *day = new DayScheduleWidget(this->sch->getWeeks()[this->currentWeekNumber-1].getDays()[i]);
            day->setFixedWidth(296);
            day->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
            gridLayout->addWidget(day, i/3, i%3, 1, 1, Qt::AlignTop);
        };
    };

    gridLayout->setHorizontalSpacing(32);   // расстояние между столбцами
    gridLayout->setVerticalSpacing(32);   // расстояние между строками
    mainVLayout->addLayout(gridLayout);
}
