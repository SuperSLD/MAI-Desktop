#include "splashfragment.h"

#include <QDebug>
#include <QSvgWidget>
#include <QTimer>


#include <implfragmentfactory.h>
#include <stylecontainer.h>

#include <data/appsettingsrepository.h>
using namespace screens;
using namespace styles;

SplashFragment::SplashFragment() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QSvgWidget *centerConainer = new QSvgWidget(":/resc/resc/splash.svg");

    centerConainer->setStyleSheet(SPLASH_ICON);

    mainHLayout->addWidget(centerConainer);
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    this->setObjectName("fragment");
    this->setLayout(mainVLayout);

    QTimer::singleShot(1000, this, SLOT(openStartScreen()));
}

SplashFragment::~SplashFragment() {

}

void SplashFragment::openStartScreen() {
    AppSettingsRepository settingsRep = AppSettingsRepository();
    if (settingsRep.containsGroup()) {
        qDebug() << "SplashFragment: open main menu";
        emit navigateTo(MAIN_TAG);
    } else {
        qDebug() << "SplashFragment: open search group";
        emit navigateTo(SEARCH_GROUP);
    }
}
