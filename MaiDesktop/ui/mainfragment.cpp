#include "mainfragment.h"

#include <ui/items/mainmenubuttonwidget.h>

#include <ui/widgets/swgbutton.h>

#include <QLabel>

#include <stylecontainer.h>

using namespace styles;
#include <implfragmentfactory.h>

#include <data/appsettingsrepository.h>
using namespace screens;

MainFragment::MainFragment() {

    // подключение репозитория
    netRep = new AppNetRepository();
    connect(netRep, &AppNetRepository::listenSchedule, this, &MainFragment::listenSchedule);

    AppSettingsRepository settingsRep = AppSettingsRepository();
    GroupModel group = settingsRep.getGroup();

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

    QLabel *titleLabel = new QLabel(group.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
    );
    titleLabel->setFont(QFont("Roboto", 36, QFont::Normal));
    secondaryLayout->addWidget(titleLabel);
    SwgButton *backButton = new SwgButton(":/resc/resc/Vector.svg", QSize(20,18));
    connect(backButton, &SwgButton::clicked, this, &MainFragment::onExit);
    secondaryLayout->addWidget(backButton);

    QLabel *titleInstituteLabel = new QLabel(group.getFaculty());
    titleInstituteLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    titleInstituteLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    headerLayout->addWidget(titleInstituteLabel);
    QLabel *titleTypeLabel = new QLabel(group.getLevel());
    titleTypeLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    titleTypeLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    headerLayout->addWidget(titleTypeLabel);
    QLabel *titleCourseLabel = new QLabel("Курс " + QString::number(group.getCourse()));
    titleCourseLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    titleCourseLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    headerLayout->addWidget(titleCourseLabel);
    headerLayout->setContentsMargins(24,24,24,24);

    QLabel *titleChosenGroup = new QLabel("Выбранная группа");
    titleChosenGroup->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    titleChosenGroup->setFont(QFont("Roboto", 14, QFont::Normal));
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
    netRep->getSchedule(group.getId());
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
        ScheduleModel *sch = &schedule;
        emit navigateWhithData(WEEK_SCHEDULE, sch);
    } else if (code == EXAMS) {
        ScheduleModel *sch = &schedule;
        emit navigateWhithData(EXAM_SCHEDULE, sch);
    } else if (code == PLANING) {
        emit navigateTo(OPTIMAL_GROUPS_TAG);
    } else if (code == INFORmAtION) {
        emit navigateTo(INFORMATION_TAG);
    }
}

void MainFragment::onExit() {
    AppSettingsRepository settingsRep = AppSettingsRepository();
    settingsRep.deleteGroup();
    emit replace(SEARCH_GROUP);
}
