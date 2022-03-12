#include "lectormodel.h"

LectorModel::LectorModel() {}
LectorModel::LectorModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
}

QString LectorModel::getId() { return id; }
QString LectorModel::getName() { return name; }
