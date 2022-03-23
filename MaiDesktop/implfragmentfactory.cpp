#include "implfragmentfactory.h"

#include <QString>

#include <ui/mainfragment.h>
#include <ui/searchgroupfragment.h>
#include <ui/splashfragment.h>
#include <ui/schedule/examschedulefragment.h>
#include <ui/schedule/selectweekfragment.h>
#include <ui/information/canteensfragment.h>
#include <ui/information/creativefragment.h>
#include <ui/information/informationfragment.h>
#include <ui/information/libraryfragment.h>
#include <ui/information/sportfragment.h>
#include <ui/information/studorgfragment.h>

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
    } else if (tag == EXAM_SCHEDULE) {
        return new ExamScheduleFragment;
    } else if (tag == CANTEENS_TAG) {
        return new CanteensFragment;
    } else if (tag == LIBRARY_TAG) {
        return new LibraryFragment;
    } else if (tag == MAIN_TAG) {
        return new MainFragment;
    } else if (tag == SPORT_TAG) {
        return new SportFragment;
    } else if (tag == STUD_ORG_TAG) {
        return new StudOrgFragment;
    } else if (tag == CREATIVE_TAG) {
        return new CreativeFragment;
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
