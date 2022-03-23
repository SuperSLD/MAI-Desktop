#ifndef CREATIVEMODEL_H
#define CREATIVEMODEL_H

#include <qjsonvalue.h>
#include <qstring.h>

#include <common/base/basemodel.h>

class CreativeModel: public BaseModel {

private:
    QString id;
    QString name;
    QString contactName;
    QString contact;
    QString description;

public:
    CreativeModel() {}
    CreativeModel(QJsonValue obj);

    QString getId();
    QString getName();
    QString getContactName();
    QString getContact();
    QString getDescription();
};

#endif // CREATIVEMODEL_H
