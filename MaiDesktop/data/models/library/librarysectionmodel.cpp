#include "librarysectionmodel.h"

#include <QJsonObject>
#include <QJsonValue>

LibrarySectionModel::LibrarySectionModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->location = obj["location"].toString();
}

QString LibrarySectionModel::getId() { return id; }
QString LibrarySectionModel::getName() { return name; }
QString LibrarySectionModel::getLocation() { return location; }
