#include "studorglist.h"
#include "studorgmodel.h"

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

StudOrgList::StudOrgList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(StudOrgModel(item));
    }
}
