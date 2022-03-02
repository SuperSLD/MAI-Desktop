#ifndef SEARCHGROUPFRAGMENT_H
#define SEARCHGROUPFRAGMENT_H

#include <common/base/basefragment.h>

#include <data/appnetrepository.h>



class SearchGroupFragment: public BaseFragment {
    Q_OBJECT

private:
    AppNetRepository *netRepository;
    QVBoxLayout *mainVLayout;
public:
    SearchGroupFragment();
    ~SearchGroupFragment();
public slots:
    void listenGroups(QJsonObject object);

};

#endif // SEARCHGROUPFRAGMENT_H
