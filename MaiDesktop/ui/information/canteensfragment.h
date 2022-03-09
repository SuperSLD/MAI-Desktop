#ifndef CANTEENSFRAGMENT_H
#define CANTEENSFRAGMENT_H

#include <QWidget>
#include <common/base/basefragment.h>
#include <ui/widgets/loadingcontainerwidget.h>
#include <data/appnetrepository.h>

class CanteensFragment : public BaseFragment {
    Q_OBJECT

private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;

public:
    CanteensFragment();
    ~CanteensFragment();

private slots:
    void onBackPressed();
    void listenCanteens(DataWrapper<CanteensList> wrapper);
};

#endif // CANTEENSFRAGMENT_H
