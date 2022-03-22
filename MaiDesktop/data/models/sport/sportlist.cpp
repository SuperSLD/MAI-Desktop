#include "sportlist.h"

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

SportList::SportList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(SportModel(item));
    }
}
