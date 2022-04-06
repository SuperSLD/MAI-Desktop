#ifndef OPTIMALINFOFRAGMENT_H
#define OPTIMALINFOFRAGMENT_H

#include <common/base/basefragment.h>

class OptimalInfoFragment : public BaseFragment {
public:
    OptimalInfoFragment();
    //void bindData(BaseModel* model) override;
private slots:
    void onBackPressed();
};

#endif // OPTIMALINFOFRAGMENT_H
