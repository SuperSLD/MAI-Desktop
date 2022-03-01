#include "implfragmentfactory.h"

#include <QString>

#include <ui/searchgroupfragment.h>
#include <ui/splashfragment.h>


using namespace screens;

ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == MAIN_MENU_TAG) {
        return new SearchGroupFragment;
    } else {
        return nullptr;
    }
}

//hui
QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
