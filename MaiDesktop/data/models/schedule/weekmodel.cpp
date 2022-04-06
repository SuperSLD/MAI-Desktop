#include "weekmodel.h"

#include <QJsonArray>
#include <QJsonValue>

WeekModel::WeekModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->number = obj["number"].toInt();
    this->date = obj["date"].toString();

    QJsonArray items = obj["days"].toArray();
    foreach(QJsonValue item, items) {
        days.append(DayModel(item));
    }
}

int WeekModel::getNumber() {return number;}
QString WeekModel::getDate() {return date;}
QList<DayModel> WeekModel::getDays() {return days;}
