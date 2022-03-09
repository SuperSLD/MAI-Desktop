#ifndef INFORMATIONFRAGMENT_H
#define INFORMATIONFRAGMENT_H

#include <QObject>

#include <common/base/basefragment.h>

class InformationFragment : public BaseFragment {

private:
    const int CANTEENS = 0;
    const int LIBRARIES = 1;
    const int SPORT = 2;
    const int GROUPS = 3;
    const int CREATIVE = 4;

public:
    InformationFragment();
    ~InformationFragment();

slots
    void onBackPressed();
    void onMenuButtonClick(int code);
};

#endif // INFORMATIONFRAGMENT_H
