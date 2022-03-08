#include "subjectmodel.h"

#include <QJsonValue>

SubjectModel::SubjectModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->id = obj["id"].toString();
    this->number = obj["number"].toString();
    this->name = obj["number"].toString();
    this->room = RoomModel(obj["room"]);
    this->lector = LectorModel(obj["lector"]);
    this->name = obj["number"].toString();
    this->timeStart = obj["timeStart"].toString();
    this->timeEnd = obj["timeEnd"].toString();
    this->type = obj["type"].toString();
    this->link = obj["link"].toString();

}

QString SubjectModel::getId() { return id; }
QString SubjectModel::getNumber() { return number; }
QString SubjectModel::getName() { return name; }
LectorModel SubjectModel::getLector() {return lector;}
RoomModel SubjectModel::getRoom() {return room;}
QString SubjectModel::getTimeStart() {return timeStart;}
QString SubjectModel::getTimeEnd() {return timeEnd;}
QString SubjectModel::getType() {return type;}
QString SubjectModel::getLink() {return link;}

