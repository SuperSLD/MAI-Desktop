#include "weekmodel.h"

#include <QJsonArray>
#include <QJsonValue>

WeekModel::WeekModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->number = obj["number"].toInt();
    this->date = obj["date"].toString();
    this->current = obj["current"].toBool();

    QJsonArray items = obj["days"].toArray();
    foreach(QJsonValue item, items) {
        days.append(DayModel(item));
    }
}

int WeekModel::getNumber() {return number;}
QString WeekModel::getDate() {return date;}
bool WeekModel::getCurrent() {return current;}
QList<DayModel> WeekModel::getDays() {return days;}
void WeekModel::setIsCurrent(bool isCurrent) {
    this->current = isCurrent;
}
