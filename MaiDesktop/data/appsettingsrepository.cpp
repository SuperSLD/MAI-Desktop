#include "appsettingsrepository.h"

AppSettingsRepository::AppSettingsRepository() {
     settings = new QSettings("settings.ini", QSettings::IniFormat);
}

AppSettingsRepository::~AppSettingsRepository() {
    delete settings;
}


void AppSettingsRepository::saveGroup(GroupModel group) {
    settings->setValue("group_id", group.getId());
    settings->setValue("group_course", group.getCourse());
    settings->setValue("group_fac", group.getFaculty());
    settings->setValue("group_name", group.getName());
    settings->setValue("group_level", group.getLevel());
    settings->sync();
}

GroupModel AppSettingsRepository::getGroup() {
    return GroupModel(
        settings->value("group_id", "").toString(),
        settings->value("group_name", "").toString(),
        settings->value("group_fac", "").toString(),
        settings->value("group_level", "").toString(),
        settings->value("group_course", 0).toInt()
    );
}

void AppSettingsRepository::deleteGroup() {
    settings->setValue("group_id", "");
    settings->setValue("group_course", 0);
    settings->setValue("group_fac", "");
    settings->setValue("group_name", "");
    settings->setValue("group_level", "");
    settings->sync();
}

bool AppSettingsRepository::containsGroup() {
    return settings->value("group_id", "") != "";
}
