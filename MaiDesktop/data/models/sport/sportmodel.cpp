#include "sportmodel.h"

#include <QJsonArray>
#include <QJsonValue>

SportModel::SportModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    QJsonArray items = obj["sections"].toArray();
    foreach(QJsonValue item, items) {
        sections.append(SportSectionModel(item));
    }

    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->address = obj["address"].toString();
}

QList<SportSectionModel> SportModel::getSections() {return sections;}
QString SportModel::getId() {return id;}
QString SportModel::getName() {return name;}
QString SportModel::getAddress() {return address;}

