#include "mainfragment.h"

#include <ui/items/mainmenubuttonwidget.h>

#include <ui/widgets/swgbutton.h>

#include <QLabel>

#include <stylecontainer.h>

using namespace styles;


MainFragment::MainFragment()
{
    // главный контейнер
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    QGridLayout *gridLayout = new QGridLayout;
    QFrame *informationCardFrame = new QFrame;
    informationCardFrame->setMinimumHeight(20);
    informationCardFrame->setStyleSheet(
                "QFrame#section{background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                "stop:0 #0596FF, stop:1 #8773FF)}"
    );
    informationCardFrame->setObjectName("section");
    QVBoxLayout *headerLayout = new QVBoxLayout;
    informationCardFrame->setLayout(headerLayout);
    QHBoxLayout *secondaryLayout = new QHBoxLayout;
    headerLayout->addLayout(secondaryLayout);
    QLabel *titleLabel = new QLabel("М1О-309С-19");
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:36px;"
    );
    secondaryLayout->addWidget(titleLabel);
    SwgButton *backButton = new SwgButton(":/resc/resc/arrow_back.svg", QSize(24,24));
    secondaryLayout->addWidget(backButton);

    QLabel *titleInstituteLabel = new QLabel("Институт");
    titleInstituteLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    headerLayout->addWidget(titleInstituteLabel);

    QLabel *titleTypeLabel = new QLabel("Бакалавриат или специалитет");
    titleTypeLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    headerLayout->addWidget(titleTypeLabel);

    QLabel *titleCourseLabel = new QLabel("Курс");
    titleCourseLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    headerLayout->addWidget(titleCourseLabel);






    MainMenuButtonWidget *b1 = new MainMenuButtonWidget("строчка", "Расписание занятий", "Найдено 35 учебных недель");
    MainMenuButtonWidget *b2 = new MainMenuButtonWidget("строчк", "Расписание заняти", "Найдено 35 учебных недел");
    MainMenuButtonWidget *b3 = new MainMenuButtonWidget("строч", "Расписание занят", "Найдено 35 учебных неде");
    MainMenuButtonWidget *b4 = new MainMenuButtonWidget("стро", "Расписание заня", "Найдено 35 учебных нед");

    gridLayout->addWidget(informationCardFrame, 0, 0, 1, 2);
    gridLayout->addWidget(b1, 1, 0, 1, 1);
    gridLayout->addWidget(b2, 1, 1, 1, 1);
    gridLayout->addWidget(b3, 2, 0, 1, 1);
    gridLayout->addWidget(b4, 2, 1, 1, 1);

    mainVLayout->addLayout(gridLayout);
    this->setLayout(mainHLayout);
}
MainFragment::~MainFragment()
{

}
