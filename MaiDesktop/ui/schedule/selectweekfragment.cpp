#include "selectweekfragment.h"

#include <QDebug>
#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>

#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/toolbarwidget.h>

using namespace screens;
using namespace styles;


void SelectWeekFragment::onBackPressed() {
    emit back();
}


void SelectWeekFragment::onWeekPressed() {
    int currentNum = (((QPushButton*)sender())->objectName()).toInt();
    this->sch->setCurrentWeekNumber(currentNum);   // назначаем выбранную неделю
    emit replaceWhithData(WEEK_SCHEDULE, this->sch);
}


SelectWeekFragment::SelectWeekFragment() {
}

void SelectWeekFragment::bindData(BaseModel* model) {
    this->sch = dynamic_cast<ScheduleModel*>(model);

    // Прокручивающийся контейнер
    QVBoxLayout *scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(25, 25, 25, 35);

    QHBoxLayout *ContainerHLayout = new QHBoxLayout; // выравнивание по горизонтали

    // Работаем с тулбаром
    ToolbarWidget *toolbar = new ToolbarWidget("Выбор недели", true);
    toolbar->setFixedHeight(71);
    toolbar->setFixedWidth(952);
    // При нажатии на стрелочку переходим к предыдущему экрану
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &SelectWeekFragment::onBackPressed);  // слот-сигнал
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
    mainHLayout->setAlignment(Qt::AlignCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);
    scrolConttent->setLayout(mainHLayout);

    this->setLayout(scrollContainerLayout);  // назначение главного лейута

    QGridLayout *gridLayout = new QGridLayout;  // сетка

    // работаем с отдельными неделями
    int countWeeks = this->sch->getWeeks().size();
    for (int i=0; i<countWeeks; i++) {
        if (i+1 == this->sch->getCurrentWeekNumber()) {
            blockWeek = new NumWeekWidget(QString::number(i+1), true);
        } else {
            blockWeek = new NumWeekWidget(QString::number(i+1), false);
        };
        blockWeek->setObjectName(QString::number(i+1));
        connect(blockWeek, &NumWeekWidget::clicked, this, &SelectWeekFragment::onWeekPressed);  // слот-сигнал
        gridLayout->addWidget(blockWeek,i/4,i%4,1,1);
    };
    gridLayout->setHorizontalSpacing(20);   // расстояние между столбцами
    gridLayout->setVerticalSpacing(20);   // расстояние между строками
    mainVLayout->addLayout(gridLayout);
};
