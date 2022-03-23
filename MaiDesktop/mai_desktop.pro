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
    data/appsettingsrepository.cpp \
    data/models/canteens/canteenmodel.cpp \
    data/models/canteens/canteenslist.cpp \
    data/models/creative/creativelist.cpp \
    data/models/creative/creativemodel.cpp \
    data/models/datawrapper.cpp \
    data/models/group/grouplist.cpp \
    data/models/group/groupmodel.cpp \
    data/models/library/librarylist.cpp \
    data/models/library/librarymodel.cpp \
    data/models/library/librarysectionmodel.cpp \
    data/models/optimal/optimaldaymodel.cpp \
    data/models/optimal/optimalmodel.cpp \
    data/models/optimal/optimaltimemodel.cpp \
    data/models/schedule/daymodel.cpp \
    data/models/schedule/lectormodel.cpp \
    data/models/schedule/roommodel.cpp \
    data/models/schedule/schedulemodel.cpp \
    data/models/schedule/subjectmodel.cpp \
    data/models/schedule/weekmodel.cpp \
    data/models/sport/sportlist.cpp \
    data/models/sport/sportmodel.cpp \
    data/models/sport/sportsectionmodel.cpp \
    data/models/studorg/studorglist.cpp \
    data/models/studorg/studorgmodel.cpp \
    implfragmentfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    stylecontainer.cpp \
    ui/information/canteensfragment.cpp \
    ui/information/creativefragment.cpp \
    ui/information/informationfragment.cpp \
    ui/information/items/canteenitemwidget.cpp \
    ui/information/items/creativeitemwidget.cpp \
    ui/information/items/libraryitemwidget.cpp \
    ui/information/items/menubuttonwidget.cpp \
    ui/information/items/menuheaderwidget.cpp \
    ui/information/items/sportitemwidget.cpp \
    ui/information/items/studorgitemwidget.cpp \
    ui/information/libraryfragment.cpp \
    ui/items/mainmenubuttonwidget.cpp \
    ui/mainfragment.cpp \
    ui/information/sportfragment.cpp \
    ui/information/studorgfragment.cpp \
    ui/schedule/items/numweekwidget.cpp \
    ui/schedule/selectweekfragment.cpp \
    ui/searchgroupfragment.cpp \
    ui/splashfragment.cpp \
    ui/widgets/cardwidget.cpp \
    ui/widgets/codeview/codestyle.cpp \
    ui/widgets/codeview/codestyles/cppcodestyle.cpp \
    ui/widgets/codeview/codestyles/jsoncodestyle.cpp \
    ui/widgets/codeview/codeviewwidget.cpp \
    ui/widgets/loadingcontainerwidget.cpp \
    ui/widgets/slidingstackedwidget.cpp \
    ui/widgets/swgbutton.cpp \
    ui/widgets/toolbarwidget.cpp \
    ui/widgets/waitingspinnerwidget.cpp

HEADERS += \
    common/base/basefragment.h \
    common/base/basefragmentfactory.h \
    common/base/basemodel.h \
    common/router.h \
    data/apiservice.h \
    data/appnetrepository.h \
    data/appsettingsrepository.h \
    data/models/canteens/canteenmodel.h \
    data/models/canteens/canteenslist.h \
    data/models/creative/creativelist.h \
    data/models/creative/creativemodel.h \
    data/models/datawrapper.h \
    data/models/group/grouplist.h \
    data/models/group/groupmodel.h \
    data/models/library/librarylist.h \
    data/models/library/librarymodel.h \
    data/models/library/librarysectionmodel.h \
    data/models/optimal/optimaldaymodel.h \
    data/models/optimal/optimalmodel.h \
    data/models/optimal/optimaltimemodel.h \
    data/models/schedule/daymodel.h \
    data/models/schedule/lectormodel.h \
    data/models/schedule/roommodel.h \
    data/models/schedule/schedulemodel.h \
    data/models/schedule/subjectmodel.h \
    data/models/schedule/weekmodel.h \
    data/models/sport/sportlist.h \
    data/models/sport/sportmodel.h \
    data/models/sport/sportsectionmodel.h \
    data/models/studorg/studorglist.h \
    data/models/studorg/studorgmodel.h \
    implfragmentfactory.h \
    mainwindow.h \
    stylecontainer.h \
    ui/information/canteensfragment.h \
    ui/information/creativefragment.h \
    ui/information/informationfragment.h \
    ui/information/items/canteenitemwidget.h \
    ui/information/items/creativeitemwidget.h \
    ui/information/items/libraryitemwidget.h \
    ui/information/items/menubuttonwidget.h \
    ui/information/items/menuheaderwidget.h \
    ui/information/items/sportitemwidget.h \
    ui/information/items/studorgitemwidget.h \
    ui/information/libraryfragment.h \
    ui/items/mainmenubuttonwidget.h \
    ui/mainfragment.h \
    ui/information/sportfragment.h \
    ui/information/studorgfragment.h \
    ui/schedule/items/numweekwidget.h \
    ui/schedule/selectweekfragment.h \
    ui/searchgroupfragment.h \
    ui/splashfragment.h \
    ui/widgets/cardwidget.h \
    ui/widgets/codeview/codestyle.h \
    ui/widgets/codeview/codestyles/cppcodestyle.h \
    ui/widgets/codeview/codestyles/jsoncodestyle.h \
    ui/widgets/codeview/codeviewwidget.h \
    ui/widgets/loadingcontainerwidget.h \
    ui/widgets/slidingstackedwidget.h \
    ui/widgets/swgbutton.h \
    ui/widgets/toolbarwidget.h \
    ui/widgets/waitingspinnerwidget.h

RESOURCES += \
    resc.qrc \
    resc.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
