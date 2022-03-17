#include "selectweekfragment.h"

#include <QDebug>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>

#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/toolbarwidget.h>
#include <ui/schedule/items/numweekwidget.h>

using namespace screens;
using namespace styles;

SelectWeekFragment::SelectWeekFragment()
{
    // Прокручивающийся контейнер
    QVBoxLayout *scrollContainerLaout = new QVBoxLayout;
    scrollContainerLaout->setContentsMargins(0, 0, 0, 0);
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
    scrollContainerLaout->addWidget(scrollArea);

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);
    scrolConttent->setLayout(mainHLayout);

    this->setLayout(scrollContainerLaout);  // назначение главного лейута

    // работаем с туллбаром
    ToolbarWidget *toolbar = new ToolbarWidget("Выбор недели", true);
    toolbar->setFixedHeight(71);
    toolbar->setFixedWidth(952);
    mainVLayout->addWidget(toolbar);

    QGridLayout *gridLayout = new QGridLayout;  // сетка

    // работаем с отдельными неделями
    int countWeeks = 20;   // предполагаемое кол-во недель
    for (int i=0; i<countWeeks; i++) {
        NumWeekWidget *blockWeek = new NumWeekWidget(QString::number(i+1));
        gridLayout->addWidget(blockWeek,i/4,i%4,1,1);
    };
    gridLayout->setHorizontalSpacing(23);   // расстояние между столбцами
    gridLayout->setVerticalSpacing(23);   // расстояние между строками
    gridLayout->setContentsMargins(0,20,0,20);
    mainVLayout->addLayout(gridLayout);
    mainVLayout->setContentsMargins(29,29,29,29);
}
