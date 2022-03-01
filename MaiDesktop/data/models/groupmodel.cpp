#include "groupmodel.h"
#include <QJsonArray>

GroupModel::GroupModel(QJsonObject obj) : BaseModel(obj) {
    this->id = obj["id"].toString();
    this->course = obj["course"].toInt();
    this->fac = obj["fac"].toString();
    this->name = obj["name"].toString();
    this->level = obj["level"].toString();
}

QString GroupModel::getId() { return id; }
QString GroupModel::getName() { return name; }
QString GroupModel::getFaculty() { return fac; }
QString GroupModel::getLevel() { return level; }
int GroupModel::getCourse() { return course; }
