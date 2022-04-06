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
#include <qlineedit.h>

#include <ui/items/groupcounteritemwidget.h>
#include <ui/items/groupitemwidget.h>
using namespace screens;

OptimalGroupsFragment::OptimalGroupsFragment() {

    groupList = new GroupList();
    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenGroups, this, &OptimalGroupsFragment::listenGroups);

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
    QFrame *foundedListFrame = new CardWidget;
    QVBoxLayout *foundedList = new QVBoxLayout;
    QFrame *selectedListFrame = new CardWidget;
    QVBoxLayout *selectedList = new QVBoxLayout;
    foundedListFrame->setLayout(foundedList);
    foundedList->setContentsMargins(16, 16, 16, 16);
    selectedListFrame->setMinimumWidth(420);
    selectedListFrame->setLayout(selectedList);
    searchArea->addWidget(foundedListFrame);
    searchArea->addWidget(selectedListFrame);

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
    connect(searchButton, &QPushButton::clicked, this, &OptimalGroupsFragment::onSearch);
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

    // зона прокрутки для количества групп
    QScrollArea *selectedScrollArea = new QScrollArea;
    selectedScrollArea ->setFrameShape(QFrame::NoFrame);
    QWidget *selectedScrolContainer = new QWidget;
    selectedScrolContainer->setObjectName("container");
    selectedScrollArea ->setStyleSheet(SCROL_BAR);
    QHBoxLayout *selectedDeskContainer = new QHBoxLayout;
    groupsSelectedLayout = new QVBoxLayout;
    groupsSelectedLayout->setAlignment(Qt::AlignTop);
    selectedDeskContainer->addLayout(groupsSelectedLayout);
    selectedDeskContainer->setContentsMargins(0, 0, 0, 0);
    groupsSelectedLayout->setContentsMargins(0,0,0,0);
    selectedScrolContainer->setLayout(selectedDeskContainer);
    selectedScrollArea->setWidget(selectedScrolContainer);
    selectedScrollArea->setWidgetResizable(true);
    selectedScrollArea->horizontalScrollBar()->setEnabled(false);
    selectedScrollArea->verticalScrollBar()->hide();
    selectedScrollArea->verticalScrollBar()->setMaximumWidth(0);
    selectedScrollArea->setStyleSheet("background-color:"+COLOR_BACKGROUND+";");
    selectedList->addWidget(selectedScrollArea);

    // контейнер загрузки
    loadingContainer = new LoadingContainerWidget(foundedScrollArea);
    loadingContainer->error("Начните поиск");
    foundedList->addWidget(loadingContainer);

    // нижняя полоса
     QFrame *bottomLineFrame = new CardWidget;
     mainVLayout->addWidget(bottomLineFrame);
     QHBoxLayout *bottomLineContainer = new QHBoxLayout;
     bottomLineFrame->setLayout(bottomLineContainer);
     bottomLineContainer->setContentsMargins(16, 16, 16, 16);

     // ввод ожидаемого процента
     // поле для ввода
     percentEdit = new QLineEdit;
     percentEdit->setPlaceholderText("Введте минимальный процент посещаемости");
     percentEdit->setStyleSheet(EDIT_TEXT);
     bottomLineContainer->addWidget(percentEdit);

     // кнопка для перехода к результатом
     QPushButton *finishButton = new QPushButton("Найти");
     finishButton->setStyleSheet(BUTTON_SOLID);
     finishButton->setMinimumWidth(200);
     bottomLineContainer->addWidget(finishButton);
     bottomLineContainer->setAlignment(Qt::AlignRight);
     connect(finishButton, &QPushButton::clicked, this, &OptimalGroupsFragment::onSearchResult);
}

OptimalGroupsFragment::~OptimalGroupsFragment() {
    delete netRep;
    delete loadingContainer;
    delete groupNameEdit;
    delete groupsSelectedLayout;
    delete percentEdit;
    delete groupList;
}

void OptimalGroupsFragment::onBackPressed() {
    emit back();
}

void OptimalGroupsFragment::onSearch() {
    loadingContainer->startLoading("Поиск...");
    if (groupNameEdit->text().size() != 0) {
        netRep->searchGroups(groupNameEdit->text());
    } else {
        loadingContainer->error("Укажите название");
    }
}

void OptimalGroupsFragment::listenGroups(DataWrapper<GroupList> wrapper) {
    if (wrapper.isSuccess()) {
        loadingContainer->stopLoading();
        if (wrapper.getData().list.size() > 0) {
            foundedList = wrapper.getData().list;
            updateLists();
        } else {
            loadingContainer->error("Ничего не найдено");
        }
    } else {
        loadingContainer->error(wrapper.getMessage());
    }
}

void OptimalGroupsFragment::onSelectGroup(GroupModel group) {
    selectedList.append(group);
    updateLists();
    GroupCounterItemWidget *modelWidget = new GroupCounterItemWidget(&selectedList.last());
    connect(modelWidget, &GroupCounterItemWidget::counterUpdated, this, &OptimalGroupsFragment::onCounterUpdated);
    groupsSelectedLayout->addWidget(modelWidget);
    groupList->list = selectedList;
}

void OptimalGroupsFragment::onCounterUpdated() {
    clearList(groupsSelectedLayout);
    QList<GroupModel> newSelected;
    foreach (GroupModel model , selectedList) {
        if (model.count > 0) {
            newSelected.append(model.clone());
            GroupCounterItemWidget *modelWidget = new GroupCounterItemWidget(&newSelected.last());
            connect(modelWidget, &GroupCounterItemWidget::counterUpdated, this, &OptimalGroupsFragment::onCounterUpdated);
            groupsSelectedLayout->addWidget(modelWidget);
        }
    }
    selectedList = newSelected;
    groupList->list = newSelected;
    updateLists();
}

void OptimalGroupsFragment::updateLists() {
    clearList(groupsFoundLayout);
    foreach (GroupModel model , foundedList) {
        bool isSelected = false;
        foreach (GroupModel selectedModel , selectedList) {
            if (selectedModel.getId() == model.getId()) {
                isSelected = true;
            }
        }
        if (!isSelected) {
            GroupItemWidget *modelWidget = new GroupItemWidget(model);
            groupsFoundLayout->addWidget(modelWidget);
            connect(modelWidget, &GroupItemWidget::groupClicked, this, &OptimalGroupsFragment::onSelectGroup);
        }
    }
}

void OptimalGroupsFragment::onSearchResult() {
    groupList->percent = percentEdit->text().toInt();
    qDebug() << groupList->toParams();
    //emit navigateWhithData("tag", groupList);
}
