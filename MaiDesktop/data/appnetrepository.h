#ifndef APPNETREPOSITORY_H
#define APPNETREPOSITORY_H

#include "apiservice.h"

#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QList>
#include <QNetworkReply>
#include <QUuid>

#include <data/models/canteens/canteenslist.h>
#include <data/models/creative/creativelist.h>
#include <data/models/datawrapper.h>
#include <data/models/group/grouplist.h>
#include <data/models/library/librarylist.h>
#include <data/models/optimal/optimalmodel.h>
#include <data/models/schedule/schedulemodel.h>
#include <data/models/sport/sportlist.h>
#include <data/models/studorg/studorglist.h>


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
    AppNetRepository(bool debug = false);
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
    void getOptimalTime(GroupList list);

    /**
     * @brief getCanteens
     *
     * Получение списка столовых,
     * расположенных на территории маи.
     * Ответ приходит в: signal listenCanteens
     *
     */
    void getCanteens();

    /**
     * @brief getLibraryList
     *
     * Получение списка библиотек.
     * Ответ приходит в: signal listenLibraryList
     */
    void getLibraryList();

    /**
     * @brief getSportSections
     *
     * Получение списка спортивных секций.
     * Ответ приходит в: signal listenSportSections
     */
    void getSportSections();

    /**
     * @brief getStudentOrganisations
     *
     * Получение студенческих организаций.
     * Ответ приходит в: signal listenStudOrg
     */
    void getStudentOrganisations();

    /**
     * @brief getCreativeGroups
     *
     * Получение творческих коллективов.
     * Ответ приходит в: signal listenCreative
     */
    void getCreativeGroups();

signals:
    void listenGroups(DataWrapper<GroupList> wrapper);
    void listenSchedule(DataWrapper<ScheduleModel> wrapper);
    void listenOptimalTime(DataWrapper<OptimalModel> wrapper);
    void listenCanteens(DataWrapper<CanteensList> wrapper);
    void listenLibraryList(DataWrapper<LibraryList> wrapper);
    void listenSportSections(DataWrapper<SportList> wrapper);
    void listenStudOrg(DataWrapper<StudOrgList> wrapper);
    void listenCreative(DataWrapper<CreativeList> wrapper);
};


#endif // APPNETREPOSITORY_H
