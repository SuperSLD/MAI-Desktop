#include "creativefragment.h"

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

#include <ui/information/items/canteenitemwidget.h>
#include <ui/information/items/creativeitemwidget.h>
#include <ui/information/items/menubuttonwidget.h>
#include <ui/information/items/menuheaderwidget.h>
#include <ui/information/items/studorgitemwidget.h>
using namespace styles;
#include <implfragmentfactory.h>
using namespace screens;

CreativeFragment::CreativeFragment() {

    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenCreative, this, &CreativeFragment::listenCreative);

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->setAlignment(Qt::AlignHCenter);
    mainHLayout->addLayout(mainVLayout);
    this->setLayout(mainHLayout);

    // тулбар
    ToolbarWidget *toolbar = new ToolbarWidget("Творческие коллективы", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &CreativeFragment::onBackPressed);
    toolbar->setMinimumWidth(952);
    mainVLayout->addWidget(toolbar);

    // зона прокрутки
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setMinimumWidth(952);
    scrollArea->setMaximumWidth(952);
    scrollArea->setFrameShape(QFrame::NoFrame);
    QWidget *scrolContainer = new QWidget;
    scrolContainer->setObjectName("container");
    scrollArea->setStyleSheet(SCROL_BAR);
    QHBoxLayout *deskContainer = new QHBoxLayout;
    mainContainerLaout = new QVBoxLayout;
    mainContainerLaout->setAlignment(Qt::AlignTop);
    deskContainer->addLayout(mainContainerLaout);
    deskContainer->setContentsMargins(0, 0, 0, 0);
    mainContainerLaout->setContentsMargins(0,0,0,0);
    scrolContainer->setLayout(deskContainer);
    scrollArea->setWidget(scrolContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->verticalScrollBar()->hide();
    scrollArea->verticalScrollBar()->setMaximumWidth(0);
    mainVLayout->addWidget(scrollArea);
    mainVLayout->setAlignment(Qt::AlignTop);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    // контейнер загрузки
    loadingContainer = new LoadingContainerWidget(scrollArea);
    loadingContainer->setMaximumWidth(952);
    loadingContainer->startLoading("Поиск кого-то творческого...");
    mainVLayout->addWidget(loadingContainer);
    netRep->getCreativeGroups();
}

CreativeFragment::~CreativeFragment() {
    delete netRep;
    delete loadingContainer;
}

void CreativeFragment::onBackPressed() {
    emit back();
}

void CreativeFragment::listenCreative(DataWrapper<CreativeList> wrapper) {
    if (wrapper.isSuccess()) {
        loadingContainer->stopLoading();
        foreach (CreativeModel model , wrapper.getData().list) {
            CreativeItemWidget *modelWidget = new CreativeItemWidget(model);
            mainContainerLaout->addWidget(modelWidget);
        }
    } else {
        loadingContainer->error(wrapper.getMessage());
    }
}
