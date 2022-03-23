#include "schedulemodel.h"

#include <QJsonArray>
#include <QJsonValue>

ScheduleModel::ScheduleModel(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        weeks.append(WeekModel(item));
    }
}

QList<WeekModel> ScheduleModel::getWeeks() {return weeks;}

int ScheduleModel::examsCount() {
    // потом дописать
    return 5;
}
