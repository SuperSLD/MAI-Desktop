#ifndef WEEKMODEL_H
#define WEEKMODEL_H

#include "daymodel.h"

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>


class WeekModel: public BaseModel {

private:
    int number;
    QString date;
    bool current = false;
    QList<DayModel> days;
public:
    WeekModel() {}
    WeekModel(QJsonValue val);

    int getNumber();
    QString getDate();
    bool getCurrent();
    void setIsCurrent(bool isCurrent);
    QList<DayModel> getDays();
};

#endif // WEEKMODEL_H
