#include "studorgmodel.h"

#include <QJsonObject>
#include <QJsonValue>

StudOrgModel::StudOrgModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->contact = obj["contact"].toString();
    this->address = obj["address"].toString();
}

QString StudOrgModel::getId() { return id; }
QString StudOrgModel::getName() { return name; }
QString StudOrgModel::getContact() { return contact; }
QString StudOrgModel::getAddress() { return address; }
