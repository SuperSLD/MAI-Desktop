#include "groupmodel.h"

GroupModel::GroupModel(
        QString id,
        QString name,
        QString fac,
        QString level,
        int course
) {
    this->id = id;
    this->course = course;
    this->fac = fac;
    this->name = name;
    this->level = level;
}

QString GroupModel::getId() { return id; }
QString GroupModel::getName() { return name; }
QString GroupModel::getFaculty() { return fac; }
QString GroupModel::getLevel() { return level; }
int GroupModel::getCourse() { return course; }
