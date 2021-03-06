#include "appnetrepository.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkAccessManager>

#include "apiservice.h"

AppNetRepository::AppNetRepository(bool debug) { service = new ApiService(this, debug); }

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

void AppNetRepository::getOptimalTime(GroupList list) {
    service->post("api/schedule/lastpairtime",
          [](QJsonObject o, AppNetRepository *r) {
             r->listenOptimalTime(DataWrapper<OptimalModel>(o));
          },
          list.toParams()
    );
}

void AppNetRepository::getCanteens() {
    service->get("api/canteens/all",
         [](QJsonObject o, AppNetRepository *r) {
            r->listenCanteens(DataWrapper<CanteensList>(o));
         }
    );
}

void AppNetRepository::getLibraryList() {
    service->get("api/library/all",
         [](QJsonObject o, AppNetRepository *r) {
            r->listenLibraryList(DataWrapper<LibraryList>(o));
         }
    );
}

void AppNetRepository::getSportSections() {
    service->get("api/sport/all",
         [](QJsonObject o, AppNetRepository *r) {
            r->listenSportSections(DataWrapper<SportList>(o));
         }
    );
}

void AppNetRepository::getStudentOrganisations() {
    service->get("api/studorg/all",
         [](QJsonObject o, AppNetRepository *r) {
            r->listenStudOrg(DataWrapper<StudOrgList>(o));
         }
    );
}

void AppNetRepository::getCreativeGroups() {
    service->get("api/creative/all",
         [](QJsonObject o, AppNetRepository *r) {
            r->listenCreative(DataWrapper<CreativeList>(o));
         }
    );
}
