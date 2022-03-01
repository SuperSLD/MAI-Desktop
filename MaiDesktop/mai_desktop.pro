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
    data/appnetrepository.cpp \
    data/models/datawrapper.cpp \
    data/models/groupmodel.cpp \
    implfragmentfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    stylecontainer.cpp \
    ui/searchgroupfragment.cpp \
    ui/splashfragment.cpp \
    ui/test2fragment.cpp \
    ui/testfragment.cpp \
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
    data/appnetrepository.h \
    data/models/datawrapper.h \
    data/models/groupmodel.h \
    implfragmentfactory.h \
    mainwindow.h \
    stylecontainer.h \
    ui/searchgroupfragment.h \
    ui/splashfragment.h \
    ui/test2fragment.h \
    ui/testfragment.h \
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
