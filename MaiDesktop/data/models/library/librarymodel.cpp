#include "librarymodel.h"

#include <QJsonArray>
#include <QJsonValue>

LibraryModel::LibraryModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    QJsonArray items = obj["sections"].toArray();
    foreach(QJsonValue item, items) {
        sections.append(LibrarySectionModel(item));
    }

    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
}

QList<LibrarySectionModel> LibraryModel::getSections() {return sections;}
QString LibraryModel::getId() {return id;}
QString LibraryModel::getName() {return name;}
