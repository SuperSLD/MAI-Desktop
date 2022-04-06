#include "groupmodel.h"

#include <QJsonObject>
#include <QJsonValue>


GroupModel::GroupModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->course = obj["course"].toInt();
    this->fac = obj["fac"].toString();
    this->name = obj["name"].toString();
    this->level = obj["level"].toString();
}

GroupModel::GroupModel(
        QString id,
        QString name,
        QString fac,
        QString level,
        int course,
        int count
) {
    this->id = id;
    this->course = course;
    this->fac = fac;
    this->name = name;
    this->level = level;
    this->count = count;
}

QString GroupModel::getId() { return id; }
QString GroupModel::getName() { return name; }
QString GroupModel::getFaculty() { return fac; }
QString GroupModel::getLevel() { return level; }
int GroupModel::getCourse() { return course; }

GroupModel GroupModel::clone() {
    return GroupModel(
                this->id,
                this->name,
                this->fac,
                this->level,
                this->course,
                this->count
    );
}

QJsonObject GroupModel::toParams() {
    QJsonObject param;
    param.insert("id", id);
    param.insert("count", count);
    return param;
}
