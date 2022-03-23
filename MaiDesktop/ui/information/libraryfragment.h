#ifndef LIBRARYFRAGMENT_H
#define LIBRARYFRAGMENT_H

#include <QWidget>
#include <common/base/basefragment.h>
#include <ui/widgets/loadingcontainerwidget.h>
#include <data/appnetrepository.h>


class LibraryFragment: public BaseFragment {
    Q_OBJECT

private:
    LoadingContainerWidget *loadingContainer;
    AppNetRepository *netRep;

    QVBoxLayout *mainContainerLaout;

public:
    LibraryFragment();
    ~LibraryFragment();

private slots:
    void onBackPressed();
    void listenLibraryList(DataWrapper<LibraryList> wrapper);
};

#endif // LIBRARYFRAGMENT_H
