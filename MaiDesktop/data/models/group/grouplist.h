#ifndef GROUPLIST_H
#define GROUPLIST_H

#include "groupmodel.h"

#include <common/base/basemodel.h>


class GroupList : public BaseModel {

public:
    QList<GroupModel> list;

    GroupList(QJsonValue val);
    QJsonObject toParams(int percent);
};

#endif // GROUPLIST_H
