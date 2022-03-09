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

#include <ui/widgets/toolbarwidget.h>
using namespace styles;

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
    scrolConttent->setLayout(mainContainerLaout);

    QVBoxLayout *secondContainerLaout = new QVBoxLayout;
    QFrame *secondContainerFrame = new QFrame;
    secondContainerLaout->addWidget(secondContainerFrame);
    secondContainerFrame->setStyleSheet("background-color:#000000;");

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

    // меню
    QFrame *menuContainerFrame = new QFrame;
    QHBoxLayout *menuHContainerLaout = new QHBoxLayout();
    menuContainerFrame->setLayout(menuHContainerLaout);
    menuHContainerLaout->setAlignment(Qt::AlignHCenter);
    menuHContainerLaout->setContentsMargins(0, 0 ,0, 0);
    QVBoxLayout *menuContainerLaout = new QVBoxLayout;
    menuHContainerLaout->addLayout(menuContainerLaout);
    menuContainerLaout->setContentsMargins(0, 0, 0, 0);
    menuContainerLaout->setAlignment(Qt::AlignTop);
    QFrame *menuHeader = new QFrame;
    menuHeader->setMinimumHeight(800);
    menuHeader->setMaximumWidth(952);
    menuHeader->setMinimumWidth(952);
    menuHeader->setStyleSheet("background-color:#343434;");
    menuContainerLaout->addWidget(menuHeader);

    mainContainerLaout->addWidget(menuContainerFrame);

    this->setLayout(scrollContainerLaout);
    this->setObjectName("fragment");
}

InformationFragment::~InformationFragment() {

}
