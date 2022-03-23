#ifndef SPORTFRAGMENT_H
#define SPORTFRAGMENT_H

#include <common/base/basefragment.h>
#include <ui/widgets/loadingcontainerwidget.h>
#include <data/appnetrepository.h>

class SportFragment : public BaseFragment {
    Q_OBJECT

private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;

    QVBoxLayout *mainContainerLaout;

public:
    SportFragment();
    ~SportFragment();

private slots:
    void onBackPressed();
    void listenSportSections(DataWrapper<SportList> wrapper);
};

#endif // SPORTFRAGMENT_H
