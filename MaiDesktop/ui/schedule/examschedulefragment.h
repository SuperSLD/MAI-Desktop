#ifndef EXAMSCHEDULEFRAGMENT_H
#define EXAMSCHEDULEFRAGMENT_H

#include <common/base/basefragment.h>

class ExamScheduleFragment : public BaseFragment {

public:
    ExamScheduleFragment();

    void bindData(BaseModel* model) override;
private slots:
    void onBackPressed();
};

#endif // EXAMSCHEDULEFRAGMENT_H
