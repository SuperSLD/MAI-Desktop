#include "canteenmodel.h"

#include <QJsonObject>
#include <QJsonValue>


CanteenModel::CanteenModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->workTime = obj["workTime"].toString();
    this->address = obj["address"].toString();
}

QString CanteenModel::getId() { return id; }
QString CanteenModel::getName() { return name; }
QString CanteenModel::getWorkTime() { return workTime; }
QString CanteenModel::getAddress() { return address; }
