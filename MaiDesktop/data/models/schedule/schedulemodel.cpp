#include "schedulemodel.h"

#include <QJsonArray>
#include <QJsonValue>

ScheduleModel::ScheduleModel(QJsonValue val) {
    QJsonObject obj = val.toObject();
    this->currentWeekNumber = obj["currentWeekNumber"].toInt();

    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        weeks.append(WeekModel(item));
    }
}

QList<WeekModel> ScheduleModel::getWeeks() {return weeks;}
int ScheduleModel::getCurrentWeekNumber() {return currentWeekNumber;}
void ScheduleModel::setCurrentWeekNumber(int isCurrentWeekNumber) {
    this->currentWeekNumber = isCurrentWeekNumber;
}
int ScheduleModel::examsCount() {
    // потом дописать
    return 5;
}
