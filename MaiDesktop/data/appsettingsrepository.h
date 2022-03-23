#ifndef APPSETTINGSREPOSITORY_H
#define APPSETTINGSREPOSITORY_H

#include <qsettings.h>

#include <data/models/group/groupmodel.h>



class AppSettingsRepository {
private:
    QSettings *settings;
public:
    AppSettingsRepository();
    ~AppSettingsRepository();

    void saveGroup(GroupModel group);
    GroupModel getGroup();
    void deleteGroup();
    bool containsGroup();
};

#endif // APPSETTINGSREPOSITORY_H
