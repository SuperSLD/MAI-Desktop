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

    //информация
    static const QString INFORMATION_TAG = "information";
    static const QString CANTEENS_TAG = "canteens";
    static const QString LIBRARY_TAG = "library";

    //расписание
    static const QString SELECT_WEEK = "select_week";
};

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

    BaseFragment* create(QString tag) override;
    QString createStart() override;
};

#endif // IMPLFRAGMENTFACTORY_H
