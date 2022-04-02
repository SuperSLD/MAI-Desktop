#ifndef SELECTWEEKFRAGMENT_H
#define SELECTWEEKFRAGMENT_H

#include <common/base/basefragment.h>

#include <data/models/schedule/schedulemodel.h>

class SelectWeekFragment : public BaseFragment {

public:
    SelectWeekFragment();
    void bindData(BaseModel* model) override;
private:
    ScheduleModel *sch;
private slots:
    void onBackPressed();
    void onWeekPressed();
};

#endif // SELECTWEEKFRAGMENT_H
