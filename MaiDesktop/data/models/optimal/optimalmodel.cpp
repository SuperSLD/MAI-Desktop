#include "optimalmodel.h"
#include <QJsonArray>
#include <QJsonValue>

OptimalModel::OptimalModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    QJsonArray items = obj["weekDataList"].toArray();
    foreach(QJsonValue item, items) {
        this->weekDataList.append(OptimalDayModel(item));
    }

    this->minPercent = obj["minPercent"].toInt();
    this->total = obj["total"].toInt();
    this->groupsCount = obj["groupsCount"].toInt();
}

QList<OptimalDayModel> OptimalModel::getWeekDataList() {return weekDataList;}
int OptimalModel::getMinPercent() {return minPercent;}
int OptimalModel::getTotal() {return total;}
int OptimalModel::getGroupsCount() {return groupsCount;}

