#include "grouplist.h"

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

GroupList::GroupList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(GroupModel(item));
    }
}

QJsonObject GroupList::toParams() {
    QJsonObject param;
    param.insert("sem", 2);
    param.insert("minPercent", percent);

    QJsonArray array = QJsonArray();
    foreach (GroupModel group , list) {
        array.append(group.toParams());
    }

    param.insert("groups", array);
    return param;
}
