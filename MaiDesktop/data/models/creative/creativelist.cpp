#include "creativelist.h"

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

CreativeList::CreativeList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(CreativeModel(item));
    }
}
