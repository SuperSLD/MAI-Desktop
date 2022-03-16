#ifndef STUDORGLIST_H
#define STUDORGLIST_H

#include "studorgmodel.h"

#include <common/base/basemodel.h>

class StudOrgList: public BaseModel {

public:
    QList<StudOrgModel> list;

    StudOrgList(QJsonValue val);
    StudOrgList() {}
};

#endif // STUDORGLIST_H
