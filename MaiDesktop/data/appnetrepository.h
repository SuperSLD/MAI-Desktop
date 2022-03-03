#ifndef APPNETREPOSITORY_H
#define APPNETREPOSITORY_H

#include "apiservice.h"

#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QList>
#include <QNetworkReply>
#include <QUuid>

#include <data/models/datawrapper.h>
#include <data/models/group/grouplist.h>


/**
 * @brief The AppRepository class
 *
 * Репозиторий для получения
 * информации с сервера.
 *
 * На каждый метод сервера репозиторий
 * имеет один метод и один сигнал.
 * К сигналу подключаемся чтобы прослушивать
 * данные, а метод вызываем, чтобы
 * инициализировать отправку.
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
    void listenGroups(DataWrapper<GroupList> wrapper);

};


#endif // APPNETREPOSITORY_H
