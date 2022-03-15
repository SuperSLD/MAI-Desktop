#include "libraryfragment.h"

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
#include <ui/information/items/libraryitemwidget.h>
#include <ui/information/items/menubuttonwidget.h>
#include <ui/information/items/menuheaderwidget.h>
using namespace styles;
#include <implfragmentfactory.h>
using namespace screens;

LibraryFragment::LibraryFragment() {

    netRep = new AppNetRepository(true);
    connect(netRep, &AppNetRepository::listenLibraryList, this, &LibraryFragment::listenLibraryList);

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->setAlignment(Qt::AlignHCenter);
    mainHLayout->addLayout(mainVLayout);
    this->setLayout(mainHLayout);

    // тулбар
    ToolbarWidget *toolbar = new ToolbarWidget("Библиотеки", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &LibraryFragment::onBackPressed);
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
    loadingContainer->startLoading("Загрузка библиотек...");
    mainVLayout->addWidget(loadingContainer);
    netRep->getLibraryList();
}

LibraryFragment::~LibraryFragment() {
    delete netRep;
    delete loadingContainer;
}

void LibraryFragment::onBackPressed() {
    emit back();
}

void LibraryFragment::listenLibraryList(DataWrapper<LibraryList> wrapper) {
    if (wrapper.isSuccess()) {
        loadingContainer->stopLoading();
        foreach (LibraryModel model , wrapper.getData().list) {
            LibraryItemWidget *canteenWidget = new LibraryItemWidget(model);
            mainContainerLaout->addWidget(canteenWidget);
        }
    } else {
        loadingContainer->error(wrapper.getMessage());
    }
}
