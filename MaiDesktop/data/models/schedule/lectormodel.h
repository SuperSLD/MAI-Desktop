#ifndef LECTORMODEL_H
#define LECTORMODEL_H

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>

class LectorModel : public BaseModel {

private:
    QString id;
    QString name;

public:
    LectorModel();
    LectorModel(QJsonValue val);

    QString getId();
    QString getName();
};

#endif // LECTORMODEL_H
