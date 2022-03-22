#include "studorgitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

StudOrgItemWidget::StudOrgItemWidget(StudOrgModel model) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setAlignment(Qt::AlignTop);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_PRIMARY + ";"
        "font-size:18px;"
    );
    QLabel *phoneLabel = new QLabel(model.getContact());
    phoneLabel->setStyleSheet(
                "QLabel {"
                "   background-color:"+COLOR_PRIMARY+";"
                "   font-size:16px;"
                "   padding: 8px;"
                "   border-radius:12px;"
                "   color:"+COLOR_TEXT_PRIMARY+";"
                "}"
    );
    phoneLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    QLabel *addressTitleLabel = new QLabel("Адрес:");
    addressTitleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:14px;"
    );
    QLabel *addressLabel = new QLabel(model.getAddress());
    addressLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(phoneLabel);
    mainLayout->addWidget(addressTitleLabel);
    mainLayout->addWidget(addressLabel);

    this->setLayout(mainLayout);
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}
