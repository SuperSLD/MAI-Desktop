#ifndef SPORTLIST_H
#define SPORTLIST_H

#include "sportmodel.h"

#include <common/base/basemodel.h>

class SportList: public BaseModel {

public:
    QList<SportModel> list;
public:
    SportList() {}
    SportList(QJsonValue val);
};

#endif // SPORTLIST_H
