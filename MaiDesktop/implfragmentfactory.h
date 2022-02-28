#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>

#include <common/base/basefragmentfactory.h>


namespace screens {
    static const QString SERVER_URL = "http://jutter.online/mytask";
    //static const QString SERVER_URL = "http://localhost:8080";

    static const QString SPLASH_TAG = "splash";
    static const QString MAIN_MENU_TAG = "start";
};

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

    BaseFragment* create(QString tag) override;
    QString createStart() override;
};

#endif // IMPLFRAGMENTFACTORY_H
