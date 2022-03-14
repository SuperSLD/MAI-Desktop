#include "informationfragment.h"

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

InformationFragment::InformationFragment() {

    // прокручивающийся контеинер
    QVBoxLayout *scrollContainerLaout = new QVBoxLayout;
    scrollContainerLaout->setContentsMargins(0, 0, 0, 0);
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
    QVBoxLayout *mainContainerLaout = new QVBoxLayout;
    scrollArea->setLayout(mainContainerLaout);
    QFrame *mainContainerFrame = new QFrame;
    mainContainerLaout->addWidget(mainContainerFrame);
    mainContainerLaout->setContentsMargins(0, 0, 0, 0);
    mainContainerLaout->setSpacing(0);
    mainContainerLaout->setAlignment(Qt::AlignTop);
    scrolConttent->setLayout(mainContainerLaout);

    // фон
    QVBoxLayout *backContainerLaout = new QVBoxLayout;
    backContainerLaout->setAlignment(Qt::AlignTop);
    backContainerLaout->setContentsMargins(0, 0, 0, 0);
    mainContainerFrame->setLayout(backContainerLaout);
    // фоновый градиент
    QFrame *backGradient = new QFrame;
    backGradient->setMinimumHeight(248);
    backGradient->setMaximumHeight(248);
    backGradient->setMidLineWidth(50);
    backGradient->setStyleSheet(
                "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                "stop:0 #0596FF, stop:1 #8773FF)"
    );
    backContainerLaout->addWidget(backGradient);

    // контейнер для меню
    QVBoxLayout *menuContainer = new QVBoxLayout;
    menuContainer->setAlignment(Qt::AlignHCenter);
    menuContainer->setContentsMargins(0, 16, 0, 0);
    menuContainer->setSpacing(16);
    mainContainerLaout->addLayout(menuContainer);

    // карточка заголовка
    CardWidget *menuHeaderCard = new CardWidget;
    menuHeaderCard->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    menuHeaderCard->setMaximumWidth(952);
    menuHeaderCard->setMinimumWidth(952);
    menuContainer->addWidget(menuHeaderCard);
    QVBoxLayout *headerLayout = new QVBoxLayout;
    headerLayout->setAlignment(Qt::AlignLeft);
    headerLayout->setContentsMargins(20, 20, 20, 20);
    menuHeaderCard->setLayout(headerLayout);
    // кнопка "Назад" в заголовке
    SwgButton *backButton = new SwgButton(":/resc/resc/arrow_back.svg", QSize(24,24));
    headerLayout->addWidget(backButton);
    connect(backButton, &SwgButton::clicked, this, &InformationFragment::onBackPressed);
    // заголовок
    QLabel *titleLabel = new QLabel("МАИ");
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:48px;"
    );
    headerLayout->addWidget(titleLabel);
    // заголовок
    QLabel *subtitleLable = new QLabel("Инфомрация о кампусе маи и другая информация об активности студентов.");
    subtitleLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:18px;"
    );
    headerLayout->addWidget(subtitleLable);

    // кампус
    MenuHeaderWidget *cumpusHeader = new MenuHeaderWidget("Кампус");
    menuContainer->addWidget(cumpusHeader);

    // столовые
    MenuButtonWidget *menuButton = new MenuButtonWidget("Столовые и буфеты", "canteens", CANTEENS);
    connect(menuButton, &MenuButtonWidget::codeClicked, this, &InformationFragment::onMenuButtonClick);
    menuContainer->addWidget(menuButton);

    // библиотеки
    MenuButtonWidget *libButton = new MenuButtonWidget("Библиотеки", "libraries", LIBRARIES);
    connect(libButton, &MenuButtonWidget::codeClicked, this, &InformationFragment::onMenuButtonClick);
    menuContainer->addWidget(libButton);

    // жизнь
    MenuHeaderWidget *lifeHeader = new MenuHeaderWidget("Жизнь");
    menuContainer->addWidget(lifeHeader);

    // спортивные секции
    MenuButtonWidget *sportButton = new MenuButtonWidget("Спортивные секции", "sport", SPORT);
    connect(sportButton, &MenuButtonWidget::codeClicked, this, &InformationFragment::onMenuButtonClick);
    menuContainer->addWidget(sportButton);

    // Студенческие объединения
    MenuButtonWidget *studButton = new MenuButtonWidget("Студенческие объединения", "group", GROUPS);
    connect(studButton, &MenuButtonWidget::codeClicked, this, &InformationFragment::onMenuButtonClick);
    menuContainer->addWidget(studButton);

    // Творческие коллективы
    MenuButtonWidget *creativeButton = new MenuButtonWidget("Творческие коллективы", "creative", CREATIVE);
    connect(creativeButton, &MenuButtonWidget::codeClicked, this, &InformationFragment::onMenuButtonClick);
    menuContainer->addWidget(creativeButton);
    QWidget *space = new QWidget;
    space->setMinimumHeight(8);
    menuContainer->addWidget(space);

    this->setLayout(scrollContainerLaout);
    this->setObjectName("fragment");
}

InformationFragment::~InformationFragment() {

}

void InformationFragment::onBackPressed() {
    emit back();
}

void InformationFragment::onMenuButtonClick(int code) {
    qDebug() << "InformationFragment: click button-" << code << Qt::endl;
    if (code == CANTEENS) {
        emit navigateTo(CANTEENS_TAG);
    } else if (code == LIBRARIES) {
        emit navigateTo(LIBRARY_TAG);
    }
}
