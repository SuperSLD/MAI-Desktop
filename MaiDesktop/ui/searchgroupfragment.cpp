#include "searchgroupfragment.h"

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
#include <qlineedit.h>

#include <ui/items/groupcounteritemwidget.h>
#include <ui/items/groupitemwidget.h>
using namespace screens;

SearchGroupFragment::SearchGroupFragment() {

    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenGroups, this, &SearchGroupFragment::listenGroups);

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->setAlignment(Qt::AlignHCenter);
    mainHLayout->addLayout(mainVLayout);
    this->setLayout(mainHLayout);


    QHBoxLayout *searchArea = new QHBoxLayout;
    mainVLayout->addLayout(searchArea);
    QFrame *foundedListFrame = new CardWidget;
    foundedListFrame->setMaximumWidth(640);
    QVBoxLayout *foundedList = new QVBoxLayout;
    foundedList->setSpacing(16);
    foundedListFrame->setLayout(foundedList);
    foundedList->setContentsMargins(16, 16, 16, 16);
    searchArea->addWidget(foundedListFrame);


    // поле для ввода
    groupNameEdit = new QLineEdit;
    groupNameEdit->setPlaceholderText("Введте название группы");
    groupNameEdit->setStyleSheet(EDIT_TEXT);
    foundedList->addWidget(groupNameEdit);

    // кнопка поиска
    QHBoxLayout *searchButtonContainer = new QHBoxLayout;
    QPushButton *searchButton = new QPushButton("Найти");
    searchButton->setStyleSheet(BUTTON_SOLID);
    searchButton->setMinimumWidth(200);
    searchButtonContainer->addWidget(searchButton);
    searchButtonContainer->setAlignment(Qt::AlignRight);
    connect(searchButton, &QPushButton::clicked, this, &SearchGroupFragment::onSearch);
    foundedList->addLayout(searchButtonContainer);

    // зона прокрутки для поиска групп
    QScrollArea *foundedScrollArea = new QScrollArea;
    foundedScrollArea ->setFrameShape(QFrame::NoFrame);
    QWidget *scrolContainer = new QWidget;
    scrolContainer->setObjectName("container");
    foundedScrollArea ->setStyleSheet(SCROL_BAR);
    QHBoxLayout *deskContainer = new QHBoxLayout;
    groupsFoundLayout = new QVBoxLayout;
    groupsFoundLayout->setAlignment(Qt::AlignTop);
    deskContainer->addLayout(groupsFoundLayout);
    deskContainer->setContentsMargins(0, 0, 0, 0);
    groupsFoundLayout->setContentsMargins(0,0,0,0);
    scrolContainer->setLayout(deskContainer);
    foundedScrollArea->setWidget(scrolContainer);
    foundedScrollArea->setWidgetResizable(true);
    foundedScrollArea->horizontalScrollBar()->setEnabled(false);
    foundedScrollArea->verticalScrollBar()->hide();
    foundedScrollArea->verticalScrollBar()->setMaximumWidth(0);
    foundedScrollArea->setStyleSheet("background-color:"+COLOR_BACKGROUND+";");
    foundedList->addWidget(foundedScrollArea );

    // контейнер загрузки
    loadingContainer = new LoadingContainerWidget(foundedScrollArea);
    loadingContainer->error("Начните поиск");
    foundedList->addWidget(loadingContainer);


}

SearchGroupFragment::~SearchGroupFragment() {
    delete netRep;
    delete loadingContainer;
    delete groupNameEdit;
}

void SearchGroupFragment::onSearch() {
    loadingContainer->startLoading("Поиск...");
    if (groupNameEdit->text().size() != 0) {
        netRep->searchGroups(groupNameEdit->text());
    } else {
        loadingContainer->error("Укажите название");
    }
}

void SearchGroupFragment::listenGroups(DataWrapper<GroupList> wrapper) {
    if (wrapper.isSuccess()) {
        loadingContainer->stopLoading();
        if (wrapper.getData().list.size() > 0) {
            foreach (GroupModel model , wrapper.getData().list) {

                    GroupItemWidget *modelWidget = new GroupItemWidget(model);
                    groupsFoundLayout->addWidget(modelWidget);
                    groupsFoundLayout->setSpacing(12);
                    connect(modelWidget, &GroupItemWidget::groupClicked, this, &SearchGroupFragment::onSelectGroup);

            }
        } else {
            loadingContainer->error("Ничего не найдено");
        }
    } else {
        loadingContainer->error(wrapper.getMessage());
    }
}

void SearchGroupFragment::onSelectGroup(GroupModel group) {

}
