QT += core gui
QT += network
QT += sql
QT += widgets
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/base/basefragment.cpp \
    common/base/basefragmentfactory.cpp \
    common/base/basemodel.cpp \
    common/router.cpp \
    data/apiservice.cpp \
    data/appnetrepository.cpp \
    data/models/datawrapper.cpp \
    data/models/group/grouplist.cpp \
    data/models/group/groupmodel.cpp \
    data/models/optimal/optimaldaymodel.cpp \
    data/models/optimal/optimalmodel.cpp \
    data/models/optimal/optimaltimemodel.cpp \
    data/models/schedule/daymodel.cpp \
    data/models/schedule/lectormodel.cpp \
    data/models/schedule/roommodel.cpp \
    data/models/schedule/schedulemodel.cpp \
    data/models/schedule/subjectmodel.cpp \
    data/models/schedule/weekmodel.cpp \
    implfragmentfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    stylecontainer.cpp \
    ui/searchgroupfragment.cpp \
    ui/splashfragment.cpp \
    ui/widgets/codeview/codestyle.cpp \
    ui/widgets/codeview/codestyles/cppcodestyle.cpp \
    ui/widgets/codeview/codestyles/jsoncodestyle.cpp \
    ui/widgets/codeview/codeviewwidget.cpp \
    ui/widgets/slidingstackedwidget.cpp \
    ui/widgets/swgbutton.cpp \
    ui/widgets/toolbarwidget.cpp

HEADERS += \
    common/base/basefragment.h \
    common/base/basefragmentfactory.h \
    common/base/basemodel.h \
    common/router.h \
    data/apiservice.h \
    data/appnetrepository.h \
    data/models/datawrapper.h \
    data/models/group/grouplist.h \
    data/models/group/groupmodel.h \
    data/models/optimal/optimaldaymodel.h \
    data/models/optimal/optimalmodel.h \
    data/models/optimal/optimaltimemodel.h \
    data/models/schedule/daymodel.h \
    data/models/schedule/lectormodel.h \
    data/models/schedule/roommodel.h \
    data/models/schedule/schedulemodel.h \
    data/models/schedule/subjectmodel.h \
    data/models/schedule/weekmodel.h \
    implfragmentfactory.h \
    mainwindow.h \
    stylecontainer.h \
    ui/searchgroupfragment.h \
    ui/splashfragment.h \
    ui/widgets/codeview/codestyle.h \
    ui/widgets/codeview/codestyles/cppcodestyle.h \
    ui/widgets/codeview/codestyles/jsoncodestyle.h \
    ui/widgets/codeview/codeviewwidget.h \
    ui/widgets/slidingstackedwidget.h \
    ui/widgets/swgbutton.h \
    ui/widgets/toolbarwidget.h

RESOURCES += \
    resc.qrc \
    resc.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
