#ifndef LIBRARYSECTIONMODEL_H
#define LIBRARYSECTIONMODEL_H

#include <common/base/basemodel.h>
#include <qjsonvalue.h>

class LibrarySectionModel : public BaseModel {

private:
    QString id;
    QString name;
    QString location;

public:
    LibrarySectionModel() {}
    LibrarySectionModel(QJsonValue obj);

    QString getId();
    QString getName();
    QString getLocation();
};

#endif // LIBRARYSECTIONMODEL_H
