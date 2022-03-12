#ifndef OPTIMALMODEL_H
#define OPTIMALMODEL_H

#include "optimaldaymodel.h"

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>


class OptimalModel: public BaseModel {

private:
    QList<OptimalDayModel> weekDataList;
    int minPercent;
    int total;
    int groupsCount;

public:
    OptimalModel() {}
    OptimalModel(QJsonValue val);

    QList<OptimalDayModel> getWeekDataList();
    int getMinPercent();
    int getTotal();
    int getGroupsCount();
};

#endif // OPTIMALMODEL_H
