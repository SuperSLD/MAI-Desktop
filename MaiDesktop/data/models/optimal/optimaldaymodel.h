#ifndef OPTIMALDAYMODEL_H
#define OPTIMALDAYMODEL_H

#include "optimaltimemodel.h"

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>


class OptimalDayModel: public BaseModel {

private:
    QString name;
    QList<OptimalTimeModel> timeData;

public:
    OptimalDayModel() {}
    OptimalDayModel(QJsonValue val);

    QString getName();
    QList<OptimalTimeModel> getTimeData();
};

#endif // OPTIMALDAYMODEL_H
