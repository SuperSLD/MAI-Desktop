#include "canteenitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

CanteenItemWidget::CanteenItemWidget(CanteenModel model) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_PRIMARY + ";"
        "font-size:18px;"
    );
    QLabel *addressLabel = new QLabel(model.getAddress());
    addressLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    QLabel *timeLable = new QLabel(model.getWorkTime());
    timeLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:14px;"
    );

    mainLayout->addWidget(timeLable);
    mainLayout->addWidget(addressLabel);
    mainLayout->addWidget(titleLabel);
    this->setLayout(mainLayout);
}
