#ifndef WEEKSCHEDULEFRAGMENT_H
#define WEEKSCHEDULEFRAGMENT_H

#include <common/base/basefragment.h>

class WeekScheduleFragment : public BaseFragment {

public:
    WeekScheduleFragment();
    void bindData(BaseModel* model) override;
private:
    BaseModel* mainModel;
    int currentWeekNumber;
private slots:
    void onBackPressed();
    void onButtinPressed();
};

#endif // WEEKSCHEDULEFRAGMENT_H
