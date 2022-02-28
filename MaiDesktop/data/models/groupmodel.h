#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include <common/base/basemodel.h>

#include <QString>



class GroupModel : public BaseModel {

private:
    QString id;
    QString name;
    QString fac;
    QString level;
    int course;
public:
    GroupModel(
            QString id,
            QString name,
            QString fac,
            QString level,
            int course
    );

    QString getId();
    QString getName();
    QString getFaculty();
    QString getLevel();
    int getCourse();
};

#endif // GROUPMODEL_H
