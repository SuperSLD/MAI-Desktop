#ifndef SEARCHGROUPFRAGMENT_H
#define SEARCHGROUPFRAGMENT_H

#include <common/base/basefragment.h>

#include <ui/widgets/loadingcontainerwidget.h>

#include <data/appnetrepository.h>

#include <qlineedit.h>



class SearchGroupFragment: public BaseFragment {

private:
    LoadingContainerWidget *loadingContainer;
    QVBoxLayout* groupsFoundLayout;
    QLineEdit *groupNameEdit;

    AppNetRepository *netRep;

    void updateLists();
public:
    SearchGroupFragment();
    ~SearchGroupFragment();

private slots:
    void onSearch();
    void onSelectGroup(GroupModel group);
    void listenGroups(DataWrapper<GroupList> wrapper);
};

#endif // SEARCHGROUPFRAGMENT_H
