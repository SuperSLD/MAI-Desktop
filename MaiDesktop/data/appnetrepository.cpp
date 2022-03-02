#include "appnetrepository.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkAccessManager>

#include "implfragmentfactory.h"
using namespace screens;
#include "apiservice.h"

#include <data/models/datawrapper.h>
using namespace service;


AppNetRepository::AppNetRepository() { service = new ApiService(this); }

AppNetRepository::~AppNetRepository() { delete service; }

void AppNetRepository::searchGroups(QString groupName) {
    service->get( "api/groups/search/" + groupName,
        [](QJsonObject o, AppNetRepository *r) {
            r->listenGroups(o);
        }
    );
}

