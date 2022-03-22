#ifndef SPORTSECTIONMODEL_H
#define SPORTSECTIONMODEL_H

#include <common/base/basemodel.h>
#include <qjsonvalue.h>

class SportSectionModel : public BaseModel {

private:
    QString id;
    QString name;
    QString contactName;
    QString contact;

public:
    SportSectionModel() {}
    SportSectionModel(QJsonValue obj);

    QString getId();
    QString getName();
    QString getContactName();
    QString getContact();

};

#endif // SPORTSECTIONMODEL_H
