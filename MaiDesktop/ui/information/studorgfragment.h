#ifndef STUDORGFRAGMENT_H
#define STUDORGFRAGMENT_H

#include <QWidget>
#include <common/base/basefragment.h>
#include <ui/widgets/loadingcontainerwidget.h>
#include <data/appnetrepository.h>

class StudOrgFragment: public BaseFragment {
    Q_OBJECT

private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;

    QVBoxLayout *mainContainerLaout;

public:
    StudOrgFragment();
    ~StudOrgFragment();

private slots:
    void onBackPressed();
    void listenStudOrg(DataWrapper<StudOrgList> wrapper);
};

#endif // STUDORGFRAGMENT_H
