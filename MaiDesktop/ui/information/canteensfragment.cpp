#include "canteensfragment.h"

#include <ui/widgets/loadingcontainerwidget.h>
#include <ui/widgets/toolbarwidget.h>

CanteensFragment::CanteensFragment() {

    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenCanteens, this, &CanteensFragment::listenCanteens);

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->setAlignment(Qt::AlignHCenter);
    mainHLayout->addLayout(mainVLayout);
    this->setLayout(mainHLayout);

    // тулбар
    ToolbarWidget *toolbar = new ToolbarWidget("Столовые и буфеты", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &CanteensFragment::onBackPressed);
    toolbar->setMinimumWidth(952);
    mainVLayout->addWidget(toolbar);

    // список
    QFrame *listFrame = new QFrame;

    // контейнер загрузки
    loadingContainer = new LoadingContainerWidget(listFrame);
    loadingContainer->setMaximumWidth(952);
    loadingContainer->startLoading("Поиск столовых...");
    mainVLayout->addWidget(loadingContainer);
    netRep->getCanteens();
}

CanteensFragment::~CanteensFragment() {
    delete netRep;
    delete loadingContainer;
}

void CanteensFragment::onBackPressed() {
    emit back();
}

void CanteensFragment::listenCanteens(DataWrapper<CanteensList> wrapper) {
    //loadingContainer->stopLoading();
}

