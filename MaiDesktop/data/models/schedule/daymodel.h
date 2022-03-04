#ifndef DAYMODEL_H
#define DAYMODEL_H

#include "subjectmodel.h"

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>

class DayModel: public BaseModel {

private:
    QString id;
    QString date;
    QString name;
    QList<SubjectModel> subjects;

public:
    DayModel() {}
    DayModel(QJsonValue val);

    QString getId();
    QString getDate();
    QString getName();
    QList<SubjectModel> getSubjects();
};

#endif // DAYMODEL_H
