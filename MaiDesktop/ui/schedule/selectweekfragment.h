#ifndef SELECTWEEKFRAGMENT_H
#define SELECTWEEKFRAGMENT_H

#include <common/base/basefragment.h>

class SelectWeekFragment : public BaseFragment {

public:
    SelectWeekFragment();
    void bindData(BaseModel* model) override;
private:
    BaseModel* mainModel;
private slots:
    void onBackPressed();
    void onWeekPressed();
};

#endif // SELECTWEEKFRAGMENT_H
