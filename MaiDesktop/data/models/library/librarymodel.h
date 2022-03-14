#ifndef LIBRARYMODEL_H
#define LIBRARYMODEL_H

#include "librarysectionmodel.h"

#include <common/base/basemodel.h>

#include <QJsonObject>
#include <QJsonValue>
#include <qstring.h>

class LibraryModel: public BaseModel {

private:
    QList<LibrarySectionModel> sections;
    QString id;
    QString name;

public:
    LibraryModel() {}
    LibraryModel(QJsonValue val);

    QList<LibrarySectionModel> getSections();
    QString getId();
    QString getName();
};

#endif // LIBRARYMODEL_H
