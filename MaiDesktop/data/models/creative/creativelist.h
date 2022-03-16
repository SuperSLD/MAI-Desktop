#ifndef CREATIVELIST_H
#define CREATIVELIST_H

#include "creativemodel.h"

#include <common/base/basemodel.h>

class CreativeList: public BaseModel {

public:
    QList<CreativeModel> list;

    CreativeList(QJsonValue val);
    CreativeList() {}
};

#endif // CREATIVELIST_H
