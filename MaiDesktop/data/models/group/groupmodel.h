#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include <qjsonvalue.h>
#include <qstring.h>

#include <common/base/basemodel.h>



class GroupModel : public BaseModel {

private:
    QString id;
    QString name;
    QString fac;
    QString level;
    int course;

public:
    int count = 0;

    GroupModel(QJsonValue obj);

    QString getId();
    QString getName();
    QString getFaculty();
    QString getLevel();
    int getCourse();

    QJsonObject toParams();
};

#endif // GROUPMODEL_H
