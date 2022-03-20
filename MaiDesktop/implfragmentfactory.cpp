#include "implfragmentfactory.h"

#include <QString>

#include <ui/searchgroupfragment.h>
#include <ui/splashfragment.h>
#include <ui/schedule/examschedulefragment.h>
#include <ui/schedule/selectweekfragment.h>
#include <ui/information/informationfragment.h>


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
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
