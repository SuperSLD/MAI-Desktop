#ifndef OPTIMALINFOFRAGMENT_H
#define OPTIMALINFOFRAGMENT_H

#include <common/base/basefragment.h>

#include <data/models/optimal/optimalmodel.h>
#include <data/appnetrepository.h>
#include <ui/widgets/loadingcontainerwidget.h>

class OptimalInfoFragment : public BaseFragment {
public:
    OptimalInfoFragment();
    void bindData(BaseModel* model) override;
private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;
    QVBoxLayout *mainVLayout;
    OptimalModel optimalTime;
private slots:
    void onBackPressed();
    void listenOptimalTime(DataWrapper<OptimalModel> wrapper);
};

#endif // OPTIMALINFOFRAGMENT_H
