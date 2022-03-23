#ifndef STUDORGMODEL_H
#define STUDORGMODEL_H

#include <qjsonvalue.h>
#include <qstring.h>

#include <common/base/basemodel.h>

class StudOrgModel: public BaseModel {

private:
    QString id;
    QString name;
    QString contact;
    QString address;

public:
    StudOrgModel() {}
    StudOrgModel(QJsonValue obj);

    QString getId();
    QString getName();
    QString getContact();
    QString getAddress();
};

#endif // STUDORGMODEL_H
