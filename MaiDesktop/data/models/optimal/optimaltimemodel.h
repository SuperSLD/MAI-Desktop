#ifndef OPTIMALTIMEMODEL_H
#define OPTIMALTIMEMODEL_H

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>

class OptimalTimeModel: public BaseModel {

private:
    QString time;
    int intTime;
    int count;
    double percent;

public:
    OptimalTimeModel() {}
    OptimalTimeModel(QJsonValue val);

    QString getTime();
    int getIntTime();
    int getCount();
    double getPercent();
};

#endif // OPTIMALTIMEMODEL_H
