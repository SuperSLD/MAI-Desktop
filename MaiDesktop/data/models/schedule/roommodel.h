#ifndef ROOMMODEL_H
#define ROOMMODEL_H

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>

class RoomModel : public BaseModel {

private:
    QString id;
    QString name;

public:
    RoomModel();
    RoomModel(QJsonValue val);

    QString getId();
    QString getName();
};

#endif // ROOMMODEL_H
