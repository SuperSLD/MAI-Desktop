#include "mainfragment.h"

#include <ui/items/mainmenubuttonwidget.h>

#include <ui/widgets/swgbutton.h>

#include <QLabel>

#include <stylecontainer.h>

using namespace styles;
#include <implfragmentfactory.h>
using namespace screens;

MainFragment::MainFragment() {

    // подключение репозитория
    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenSchedule, this, &MainFragment::listenSchedule);

    // главный контейнер
    QHBoxLayout *mainLayout = new QHBoxLayout;
    this->setLayout(mainLayout);

    QFrame *mainMenuFarame = new QFrame;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);
    mainMenuFarame->setLayout(mainHLayout);

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
    SwgButton *backButton = new SwgButton(":/resc/resc/Vector.svg", QSize(20,18));
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
    headerLayout->setContentsMargins(24,24,24,24);

    QLabel *titleChosenGroup = new QLabel("Выбранная группа");
    titleChosenGroup->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    headerLayout->addWidget(titleChosenGroup);
    titleChosenGroup->setAlignment(Qt::AlignRight);
    headerLayout->setContentsMargins(24,24,24,24);



    b1 = new MainMenuButtonWidget("today_calendar", "Расписание занятий", "x", SCHEDULE);
    connect(b1, &MainMenuButtonWidget::codeClicked, this, &MainFragment::onMenuButtonClick);
    b2 = new MainMenuButtonWidget("whatshot", "Расписание экзаменов", "x", EXAMS);
    connect(b2, &MainMenuButtonWidget::codeClicked, this, &MainFragment::onMenuButtonClick);
    MainMenuButtonWidget *b3 = new MainMenuButtonWidget("watch_later", "Помощь с планированием", "Поиск удобного времени", PLANING);
    connect(b3, &MainMenuButtonWidget::codeClicked, this, &MainFragment::onMenuButtonClick);
    MainMenuButtonWidget *b4 = new MainMenuButtonWidget("info", "Информация", "Информация о кампусе", INFORmAtION);
    connect(b4, &MainMenuButtonWidget::codeClicked, this, &MainFragment::onMenuButtonClick);

    gridLayout->addWidget(informationCardFrame, 0, 0, 1, 2);
    gridLayout->addWidget(b1, 1, 0, 1, 1);
    gridLayout->addWidget(b2, 1, 1, 1, 1);
    gridLayout->addWidget(b3, 2, 0, 1, 1);
    gridLayout->addWidget(b4, 2, 1, 1, 1);

    gridLayout->setHorizontalSpacing(23); // расстояние между столбцами
    gridLayout->setVerticalSpacing(23); // расстояние между строками
    mainVLayout->addLayout(gridLayout);

    // контейнер загрузки
    loadingContainer = new LoadingContainerWidget(mainMenuFarame);
    loadingContainer->setMaximumWidth(952);
    loadingContainer->startLoading("Загружаем расписание...");
    mainLayout->addWidget(loadingContainer);
    netRep->getSchedule("d1497292f31d8755ce4530f7022b519c");
}
MainFragment::~MainFragment() {
    delete netRep;
    delete loadingContainer;
}

void MainFragment::listenSchedule(DataWrapper<ScheduleModel> wrapper) {
    if (wrapper.isSuccess()) {
        loadingContainer->stopLoading();
        this->schedule = wrapper.getData();
        b1->setSubtitle("Найдено " + QString::number(schedule.getWeeks().size()) + " учебных недель");
        b2->setSubtitle("Найдено " + QString::number(schedule.examsCount()) + " экзаменов");
    } else {
        loadingContainer->error(wrapper.getMessage());
    }
}

void MainFragment::onMenuButtonClick(int code) {
    qDebug() << "InformationFragment: click button-" << code << Qt::endl;
    if (code == SCHEDULE) {
        // тут прям пишешь emit navigateTo(название, schedule)
        // Второй параметр это модель расписания (класс с расписанием)
    } else if (code == EXAMS) {
        //
    } else if (code == PLANING) {
        //
    } else if (code == INFORmAtION) {
        navigateTo(INFORMATION_TAG);
    }
}
