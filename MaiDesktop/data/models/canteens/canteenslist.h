#ifndef CANTEENSLIST_H
#define CANTEENSLIST_H

#include "canteenmodel.h"

#include <common/base/basemodel.h>


class CanteensList: public BaseModel {

public:
    QList<CanteenModel> list;

    CanteensList(QJsonValue val);
};

#endif // CANTEENSLIST_H
