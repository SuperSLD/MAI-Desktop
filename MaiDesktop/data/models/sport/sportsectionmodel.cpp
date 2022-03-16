#include "sportsectionmodel.h"

#include <QJsonObject>
#include <QJsonValue>

SportSectionModel::SportSectionModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->contact = obj["contact"].toString();
    this->contactName = obj["contactName"].toString();
}

QString SportSectionModel::getId() { return id; }
QString SportSectionModel::getName() { return name; }
QString SportSectionModel::getContact() { return contact; }
QString SportSectionModel::getContactName() { return contactName; }
