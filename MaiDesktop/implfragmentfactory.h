#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>

#include <common/base/basefragmentfactory.h>


namespace screens {
    static const QString SERVER_URL = "https://jutter.online/mai_v2";
    //static const QString SERVER_URL = "http://localhost:8080";

    //старт и поиск группы
    static const QString SPLASH_TAG = "splash";
    static const QString SEARCH_GROUP = "search_group";
    static const QString MAIN_TAG = "main_tag";


    //информация
    static const QString INFORMATION_TAG = "information";
    static const QString CANTEENS_TAG = "canteens";
    static const QString LIBRARY_TAG = "library";
    static const QString SPORT_TAG = "sport";
    static const QString STUD_ORG_TAG = "stud_org";
    static const QString CREATIVE_TAG = "creative";

    //расписание
    static const QString WEEK_SCHEDULE = "week_schedule";
    static const QString SELECT_WEEK = "select_week";
    static const QString EXAM_SCHEDULE = "exam_schedule";

    // оптимальное время
    static const QString OPTIMAL_GROUPS_TAG = "optimal_groups";

};

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

    BaseFragment* create(QString tag) override;
    QString createStart() override;
};

#endif // IMPLFRAGMENTFACTORY_H
