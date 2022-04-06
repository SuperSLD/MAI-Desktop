#ifndef WEEKSCHEDULEFRAGMENT_H
#define WEEKSCHEDULEFRAGMENT_H

#include <common/base/basefragment.h>

#include <ui/widgets/toolbarwidget.h>
#include <data/models/schedule/schedulemodel.h>

class WeekScheduleFragment : public BaseFragment {

public:
    WeekScheduleFragment();
    void bindData(BaseModel* model) override;
private:
    ScheduleModel *sch;
    int nowWeekNumber;
    int currentWeekNumber = 0;
    ToolbarWidget *toolbar;
private slots:
    void onBackPressed();
    void onButtinPressed();
};

#endif // WEEKSCHEDULEFRAGMENT_H
