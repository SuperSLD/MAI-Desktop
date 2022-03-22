#ifndef CREATIVEFRAGMENT_H
#define CREATIVEFRAGMENT_H

#include <data/models/creative/creativelist.h>
#include <QWidget>
#include <common/base/basefragment.h>
#include <ui/widgets/loadingcontainerwidget.h>
#include <data/appnetrepository.h>


class CreativeFragment: public BaseFragment {
    Q_OBJECT

private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;

    QVBoxLayout *mainContainerLaout;

public:
    CreativeFragment();
    ~CreativeFragment();

private slots:
    void onBackPressed();
    void listenCreative(DataWrapper<CreativeList> wrapper);
};

#endif // CREATIVEFRAGMENT_H
