#ifndef SUBJECTMODEL_H
#define SUBJECTMODEL_H

#include "lectormodel.h"
#include "roommodel.h"

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

#include <common/base/basemodel.h>

class SubjectModel: public BaseModel {

private:
    QString id;
    QString number;
    QString name;
    LectorModel lector;
    RoomModel room;
    QString timeStart;
    QString timeEnd;
    QString type;
    QString link;

public:
    SubjectModel() {}
    SubjectModel(QJsonValue val);

    QString getId();
    QString getNumber();
    QString getName();
    LectorModel getLector();
    RoomModel getRoom();
    QString getTimeStart();
    QString getTimeEnd();
    QString getType();
    QString getLink();

};

#endif // SUBJECTMODEL_H
