#ifndef SEARCHGROUPFRAGMENT_H
#define SEARCHGROUPFRAGMENT_H

#include <common/base/basefragment.h>



class SearchGroupFragment: public BaseFragment {
    Q_OBJECT

private:
    QVBoxLayout *mainVLayout;
public:
    SearchGroupFragment();
    ~SearchGroupFragment();
};

#endif // SEARCHGROUPFRAGMENT_H
