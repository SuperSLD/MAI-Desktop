#ifndef SPORTMODEL_H
#define SPORTMODEL_H

#include "sportsectionmodel.h"

#include <common/base/basemodel.h>

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

class SportModel: public BaseModel {

private:
    QList<SportSectionModel> sections;
    QString id;
    QString name;
    QString address;

public:
    SportModel() {}
    SportModel(QJsonValue val);

    QList<SportSectionModel> getSections();
    QString getId();
    QString getName();
    QString getAddress();
};

#endif // SPORTMODEL_H
