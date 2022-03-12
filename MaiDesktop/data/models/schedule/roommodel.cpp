#include "roommodel.h"

RoomModel::RoomModel() {}
RoomModel::RoomModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
}

QString RoomModel::getId() { return id; }
QString RoomModel::getName() { return name; }
