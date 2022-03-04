#include "appnetrepository.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkAccessManager>

#include "apiservice.h"

AppNetRepository::AppNetRepository() { service = new ApiService(this); }

AppNetRepository::~AppNetRepository() { delete service; }

void AppNetRepository::searchGroups(QString groupName) {
    service->get( "api/groups/search/" + groupName,
        [](QJsonObject o, AppNetRepository *r) {
            r->listenGroups(DataWrapper<GroupList>(o));
        }
    );
}

void AppNetRepository::getSchedule(QString groupId) {
    service->get("api/schedule/all/" + groupId,
         [](QJsonObject o, AppNetRepository *r) {
            r->listenSchedule(DataWrapper<ScheduleModel>(o));
         }
    );
}

void AppNetRepository::getOptimalTime(GroupList list, int percernt) {
    service->post("api/schedule/lastpairtime",
          [](QJsonObject o, AppNetRepository *r) {
             r->listenOptimalTime(DataWrapper<OptimalModel>(o));
          },
          list.toParams(percernt)
    );
}
