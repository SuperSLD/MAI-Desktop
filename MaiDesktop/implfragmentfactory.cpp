#include "implfragmentfactory.h"

#include <QString>

#include <ui/searchgroupfragment.h>
#include <ui/splashfragment.h>
#include <ui/schedule/selectweekfragment.h>

#include <ui/information/canteensfragment.h>
#include <ui/information/informationfragment.h>
#include <ui/information/libraryfragment.h>
#include <ui/information/sportfragment.h>

using namespace screens;

ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == SEARCH_GROUP) {
        return new SearchGroupFragment;
    } else if (tag == INFORMATION_TAG) {
        return new InformationFragment;
    } else if (tag == SELECT_WEEK) {
        return new SelectWeekFragment;
    } else if (tag == CANTEENS_TAG) {
        return new CanteensFragment;
    } else if (tag == LIBRARY_TAG) {
        return new LibraryFragment;
    } else if (tag == SPORT_TAG) {
        return new SportFragment;
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
