#include "searchgroupfragment.h"

#include <QSvgWidget>
#include <qlabel.h>
#include <qpushbutton.h>

#include <stylecontainer.h>
#include <implfragmentfactory.h>
#include <QCoreApplication>
#include <QDateTime>

#include <ui/widgets/codeview/codeviewwidget.h>

#include <ui/widgets/codeview/codestyles/cppcodestyle.h>
#include <ui/widgets/codeview/codestyles/jsoncodestyle.h>
#include <data/models/group/groupmodel.h>
#include <ui/widgets/cardwidget.h>
#include <ui/widgets/swgbutton.h>


using namespace screens;
using namespace styles;

SearchGroupFragment::SearchGroupFragment() {

    netRepository = new AppNetRepository();
    connect(netRepository, &AppNetRepository::listenGroups, this, &SearchGroupFragment::listenGroups);

    // главный контейнер
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    QFrame *informationCardFrame = new CardWidget;
    informationCardFrame->setMinimumHeight(20);
    informationCardFrame->setMinimumWidth(640);

    QFrame *groupCardFrame = new CardWidget;
    informationCardFrame->setMinimumHeight(20);
    informationCardFrame->setMinimumWidth(340);


    informationCardFrame->setObjectName("section");
    QVBoxLayout *headerLayout = new QVBoxLayout;
    informationCardFrame->setLayout(headerLayout);
    QHBoxLayout *secondaryLayout = new QHBoxLayout;
    headerLayout->addLayout(secondaryLayout);




    mainVLayout->addWidget(informationCardFrame);



    this->setLayout(mainHLayout);
    this->setObjectName("fragment");

    netRepository->searchGroups("309С");
}

SearchGroupFragment::~SearchGroupFragment() {
    delete netRepository;
}

void SearchGroupFragment::listenGroups(DataWrapper<GroupList> wrapper) {
    qDebug() << "SearchGroupFragment: listenGroups" << Qt::endl;
    foreach (GroupModel group, wrapper.getData().list) {
        qDebug() << "SearchGroupFragment:" << group.getName() <<Qt::endl;
        group.count = 3;
    }
    netRepository->getOptimalTime(wrapper.getData(), 80);
}
