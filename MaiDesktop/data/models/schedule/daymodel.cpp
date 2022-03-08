#include "daymodel.h"

#include <QJsonArray>
#include <QJsonValue>

DayModel::DayModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->name = obj["name"].toString();
    this->date = obj["date"].toString();

    QJsonArray items = obj["subjects"].toArray();
    foreach(QJsonValue item, items) {
        subjects.append(SubjectModel(item));
    }
}

QString DayModel::getId() { return id; }
QString DayModel::getDate() { return date; }
QString DayModel::getName() { return name; }
QList<SubjectModel> DayModel::getSubjects() {return subjects;}
