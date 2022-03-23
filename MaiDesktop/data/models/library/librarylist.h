#ifndef LIBRARYLIST_H
#define LIBRARYLIST_H

#include "librarymodel.h"

#include <common/base/basemodel.h>


class LibraryList: public BaseModel {

public:
    QList<LibraryModel> list;
public:
    LibraryList() {}
    LibraryList(QJsonValue val);
};

#endif // LIBRARYLIST_H
