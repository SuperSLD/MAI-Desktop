#include "selectweekfragment.h"

#include <QDebug>
#include <QSvgWidget>


#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <ui/widgets/toolbarwidget.h>

using namespace screens;
using namespace styles;

SelectWeekFragment::SelectWeekFragment()
{
    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);    // направление выравнивания (наверх)
    mainHLayout->setAlignment(Qt::AlignHCenter); // направление выравнивания (к центру)
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);   // назначение главного лейута

    ToolbarWidget *toolbar = new ToolbarWidget("Выбор недели", true);
    mainVLayout->addWidget(toolbar);
}
