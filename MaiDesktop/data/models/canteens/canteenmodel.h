#ifndef CANTEENMODEL_H
#define CANTEENMODEL_H

#include <qjsonvalue.h>
#include <qstring.h>

#include <common/base/basemodel.h>

class CanteenModel: public BaseModel {

private:
    QString id;
    QString name;
    QString workTime;
    QString address;

public:
    CanteenModel() {}
    CanteenModel(QJsonValue obj);

    QString getId();
    QString getName();
    QString getWorkTime();
    QString getAddress();
};

#endif // CANTEENMODEL_H
