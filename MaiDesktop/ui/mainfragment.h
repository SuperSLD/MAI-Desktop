#ifndef MAINFRAGMENT_H
#define MAINFRAGMENT_H

#include <common/base/basefragment.h>

#include <common/base/basefragment.h>
#include <ui/widgets/loadingcontainerwidget.h>
#include <data/appnetrepository.h>
#include <ui/items/mainmenubuttonwidget.h>

class MainFragment: public BaseFragment {
    Q_OBJECT

private:
    const int SCHEDULE = 0;
    const int EXAMS = 1;
    const int INFORmAtION = 2;
    const int PLANING = 3;

    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;
    MainMenuButtonWidget *b1;
    MainMenuButtonWidget *b2;

    ScheduleModel schedule;

public:
    MainFragment();
    ~MainFragment();

private slots:
    void onMenuButtonClick(int code);
    void listenSchedule(DataWrapper<ScheduleModel> wrapper);
};

#endif // MAINFRAGMENT_H
