#include "optimalgroupsfragment.h"

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
#include <ui/information/items/menubuttonwidget.h>
#include <ui/information/items/menuheaderwidget.h>
using namespace styles;
#include <implfragmentfactory.h>
using namespace screens;

OptimalGroupsFragment::OptimalGroupsFragment() {
    netRep = new AppNetRepository();

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->setAlignment(Qt::AlignHCenter);
    mainHLayout->addLayout(mainVLayout);
    this->setLayout(mainHLayout);

    // тулбар
    ToolbarWidget *toolbar = new ToolbarWidget("Выбор списка групп", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &OptimalGroupsFragment::onBackPressed);
    toolbar->setMinimumWidth(952);
    mainVLayout->addWidget(toolbar);

    QHBoxLayout *searchArea = new QHBoxLayout;
    mainVLayout->addLayout(searchArea);
    QVBoxLayout *foudedList = new QVBoxLayout;
    QVBoxLayout *selecredList = new QVBoxLayout;
    searchArea->addLayout(foudedList);
    searchArea->addLayout(selecredList);
}

OptimalGroupsFragment::~OptimalGroupsFragment() {
    delete netRep;
    //delete loadingContainer;
}


void OptimalGroupsFragment::onBackPressed() {
    emit back();
}
