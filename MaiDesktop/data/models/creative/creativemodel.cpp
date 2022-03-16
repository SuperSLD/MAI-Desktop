#include "creativemodel.h"

#include <QJsonObject>
#include <QJsonValue>

CreativeModel::CreativeModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->contactName = obj["contactName"].toString();
    this->contact = obj["contact"].toString();
    this->description = obj["description"].toString();
}

QString CreativeModel::getId() { return id; }
QString CreativeModel::getName() { return name; }
QString CreativeModel::getContactName() { return contactName; }
QString CreativeModel::getContact() { return contact; }
QString CreativeModel::getDescription() { return description; }
