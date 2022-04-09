#include "optimaltimemodel.h"

#include <QJsonArray>
#include <QJsonValue>

OptimalTimeModel::OptimalTimeModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->time = obj["time"].toString();
    this->intTime = obj["intTime"].toInt();
    this->count = obj["count"].toInt();
    this->percent = obj["percent"].toDouble();
}

QString OptimalTimeModel::getTime() {return time;}
int OptimalTimeModel::getIntTime() {return intTime;}
int OptimalTimeModel::getCount() {return count;}
double OptimalTimeModel::getPercent() {return percent;}
