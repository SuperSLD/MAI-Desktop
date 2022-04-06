#ifndef OPTIMALGROUPSFRAGMENT_H
#define OPTIMALGROUPSFRAGMENT_H

#include <common/base/basefragment.h>

#include <ui/widgets/loadingcontainerwidget.h>

#include <data/appnetrepository.h>



class OptimalGroupsFragment: public BaseFragment {

private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;

public:
    OptimalGroupsFragment();
    ~OptimalGroupsFragment();

private slots:
    void onBackPressed();
};

#endif // OPTIMALGROUPSFRAGMENT_H
