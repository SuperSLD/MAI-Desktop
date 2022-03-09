#include "implfragmentfactory.h"

#include <QString>

#include <ui/searchgroupfragment.h>
#include <ui/splashfragment.h>
#include <ui/schedule/selectweekfragment.h>


using namespace screens;

ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == SEARCH_GROUP) {
        return new SearchGroupFragment;
    } else if (tag == SELECT_WEEK) {
        return new SelectWeekFragment;
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
