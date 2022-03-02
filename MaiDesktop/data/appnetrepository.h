#ifndef APPNETREPOSITORY_H
#define APPNETREPOSITORY_H

#include "apiservice.h"

#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QList>
#include <QNetworkReply>
#include <QUuid>

#include <data/models/groupmodel.h>


/**
 * @brief The AppRepository class
 *
 * Репозиторий для получения
 * информации с сервера.
 *
 */
class AppNetRepository: public QObject {
    Q_OBJECT

private:
    ApiService *service;

public:
    AppNetRepository();
    ~AppNetRepository();

    void searchGroups(QString groupName);

signals:
    void listenGroups(QJsonObject response);

};


#endif // APPNETREPOSITORY_H
