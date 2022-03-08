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
#include <data/models/optimal/optimalmodel.h>
#include <data/models/schedule/schedulemodel.h>


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

    /**
     * @brief searchGroups
     *
     * Поиск группы по части названия.
     * Ответ приходит в: signal listenGroups
     *
     * @param groupName часть названия
     */
    void searchGroups(QString groupName);

    /**
     * @brief getSchedule
     *
     * Загрузка расписания по идентификатору
     * группы. Все недели.
     * Ответ приходит в: signal listenSchedule
     *
     * @param groupId
     */
    void getSchedule(QString groupId);

    /**
     * @brief getOptimalTime
     *
     * Получение оптимального времени,
     * в которое все перечисленные группы
     * могут приехать на мероприятие.
     * Ответ приходит в: signal listenOptimalTime
     *
     * @param list
     */
    void getOptimalTime(GroupList list, int percernt);

signals:
    void listenGroups(DataWrapper<GroupList> wrapper);
    void listenSchedule(DataWrapper<ScheduleModel> wrapper);
    void listenOptimalTime(DataWrapper<OptimalModel> wrapper);


};


#endif // APPNETREPOSITORY_H
