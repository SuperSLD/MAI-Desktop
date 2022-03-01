#ifndef APPNETREPOSITORY_H
#define APPNETREPOSITORY_H

#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QList>

#include <data/models/groupmodel.h>

class GroupModel;

/**
 * @brief The AppRepository class
 *
 * Репозиторий для получения
 * информации с сервера.
 *
 */
class AppNetRepository: QObject {
    Q_OBJECT

private:
    QNetworkAccessManager *networkManager;

public:
    AppNetRepository();
    ~AppNetRepository();

    void searchGroups(QString groupName);

    void makeRequrst();
signals:

    void listenGroups(QList<GroupModel> groups);
};

#endif // APPNETREPOSITORY_H
