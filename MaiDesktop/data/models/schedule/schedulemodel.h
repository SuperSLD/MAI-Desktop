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

public:
    ScheduleModel() {}
    ScheduleModel(QJsonValue val);

    QList<WeekModel> getWeeks();
};

#endif // SCHEDULEMODEL_H
