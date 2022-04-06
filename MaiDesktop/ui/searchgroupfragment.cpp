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

    // отображение исходного кода
    mainVLayout->addWidget(new CodeViewWidget(
        "/**\n"
        "  * Метод поиска группы по части\n"
        "  * ее названия.\n"
        "  *\n"
        "  * @param groupName часть названия\n"
        "  */\n"
        "void AppNetRepository::searchGroups(QString groupName) {\n"
        "   service->get( \"api/groups/search/\" + groupName,\n"
        "       [](QJsonObject o, AppNetRepository *r) {\n"
        "           r->listenGroups(DataWrapper<GroupList>(o));\n"
        "       }\n"
        "   );\n"
        "}",
        new CppCodeStyle()
    ));

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
}
