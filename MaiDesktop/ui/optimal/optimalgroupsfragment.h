#ifndef OPTIMALGROUPSFRAGMENT_H
#define OPTIMALGROUPSFRAGMENT_H

#include <common/base/basefragment.h>

#include <ui/widgets/loadingcontainerwidget.h>

#include <data/appnetrepository.h>

#include <qlineedit.h>



class OptimalGroupsFragment: public BaseFragment {

private:
    LoadingContainerWidget *loadingContainer;
    QVBoxLayout* groupsFoundLayout;
    QVBoxLayout* groupsSelectedLayout;
    QLineEdit *groupNameEdit;
    QLineEdit *percentEdit;
    GroupList *groupList;
    QList<GroupModel> foundedList;
    QList<GroupModel> selectedList;

    AppNetRepository *netRep;

    void updateLists();
public:
    OptimalGroupsFragment();
    ~OptimalGroupsFragment();

private slots:
    void onBackPressed();
    void onSearch();
    void onSelectGroup(GroupModel group);
    void onCounterUpdated();
    void onSearchResult();
    void listenGroups(DataWrapper<GroupList> wrapper);
};

#endif // OPTIMALGROUPSFRAGMENT_H
