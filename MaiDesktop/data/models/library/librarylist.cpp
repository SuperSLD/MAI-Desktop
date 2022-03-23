#include "librarylist.h"
#include "librarymodel.h"

#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

LibraryList::LibraryList(QJsonValue val) {
    QJsonArray items = val.toArray();
    foreach(QJsonValue item, items) {
        list.append(LibraryModel(item));
    }
}
