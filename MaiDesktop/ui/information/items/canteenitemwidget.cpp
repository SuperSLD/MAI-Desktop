#include "canteenitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

CanteenItemWidget::CanteenItemWidget(CanteenModel model) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setAlignment(Qt::AlignTop);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_PRIMARY + ";"
    );
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    QLabel *addressLabel = new QLabel(model.getAddress());
    addressLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
    );
    addressLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    QLabel *timeLable = new QLabel(model.getWorkTime());
    timeLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:14px;"
    );
    timeLable->setFont(QFont("Roboto", 14, QFont::Normal));
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(addressLabel);
    mainLayout->addWidget(timeLable);

    this->setLayout(mainLayout);
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}
