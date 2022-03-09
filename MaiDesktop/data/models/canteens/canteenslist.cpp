#include "canteenslist.h"

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

CanteensList::CanteensList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(CanteenModel(item));
    }
}
