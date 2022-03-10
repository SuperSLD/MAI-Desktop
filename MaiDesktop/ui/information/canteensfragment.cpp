#include "canteensfragment.h"

#include <ui/widgets/loadingcontainerwidget.h>
#include <ui/widgets/toolbarwidget.h>

#include <stylecontainer.h>
#include <implfragmentfactory.h>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QSettings>
#include <QSvgWidget>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>
#include <QScrollArea>
#include <QScrollBar>
#include <QNetworkReply>
#include <QColor>

#include <QSizePolicy>
#include <implfragmentfactory.h>

#include <ui/widgets/cardwidget.h>
#include <ui/widgets/swgbutton.h>
#include <ui/widgets/toolbarwidget.h>

#include <ui/information/items/menubuttonwidget.h>
#include <ui/information/items/menuheaderwidget.h>
using namespace styles;
#include <implfragmentfactory.h>
using namespace screens;


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
    // прокручивающийся контеинер
    QVBoxLayout *scrollContainerLaout = new QVBoxLayout;
    scrollContainerLaout->setContentsMargins(0, 0, 0, 0);
    listFrame->setLayout(scrollContainerLaout);
    // зона прокрутки
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

    // главный контеинер
    mainContainerLaout = new QVBoxLayout;
    scrollArea->setLayout(mainContainerLaout);

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
    loadingContainer->error("Хи хи питса");
}

