#include "grouplist.h"

#include <QJsonArray>
#include <QJsonValue>

GroupList::GroupList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(GroupModel(item));
    }
}
