#include "optimaldaymodel.h"

#include <QJsonArray>
#include <QJsonValue>

OptimalDayModel::OptimalDayModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->name = obj["name"].toString();

    QJsonArray items = obj["timeData"].toArray();
    foreach(QJsonValue item, items) {
        this->timeData.append(OptimalTimeModel(item));
    }
}

QString OptimalDayModel::getName() { return name; }
QList<OptimalTimeModel> OptimalDayModel::getTimeData() {return timeData;}
