#ifndef GROUPLIST_H
#define GROUPLIST_H

#include "groupmodel.h"

#include <common/base/basemodel.h>


class GroupList : public BaseModel {

public:
    QList<GroupModel> list;
    int percent;

    GroupList(QJsonValue val);
    GroupList() {}

    QJsonObject toParams();
    QJsonObject toOptimalValue(int percent);
};

#endif // GROUPLIST_H
