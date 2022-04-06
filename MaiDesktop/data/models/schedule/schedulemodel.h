#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include "weekmodel.h"

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>

class ScheduleModel: public BaseModel {

private:
    QList<WeekModel> weeks;
    int currentWeekNumber = -1;

public:
    ScheduleModel() {}
    ScheduleModel(QJsonValue val);

    QList<WeekModel> getWeeks();
    int getCurrentWeekNumber();
    void setCurrentWeekNumber(int isCurrentWeekNumber);

    int examsCount();
};

#endif // SCHEDULEMODEL_H
