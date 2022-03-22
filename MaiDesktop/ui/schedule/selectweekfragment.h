#ifndef SELECTWEEKFRAGMENT_H
#define SELECTWEEKFRAGMENT_H

#include <common/base/basefragment.h>

class SelectWeekFragment : public BaseFragment {

public:
    SelectWeekFragment();

private slots:
    void onBackPressed();
};

#endif // SELECTWEEKFRAGMENT_H
