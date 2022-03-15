#include "sportitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

SportItemWidget::SportItemWidget(SportModel model) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setAlignment(Qt::AlignTop);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_PRIMARY + ";"
        "font-size:18px;"
    );
    QLabel *addressLabel = new QLabel(model.getAddress());
    addressLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:14px;"
    );

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(addressLabel);

    for(int i = 0; i < model.getSections().size(); i+=2) {
        QHBoxLayout *sectionContainer = new QHBoxLayout;
        sectionContainer->setAlignment(Qt::AlignLeft);
        for (int j = 0; j < 2; j++) {
            if (i + j < model.getSections().size()) {
                SportSectionModel section = model.getSections()[j + i];
                QFrame *sectionFrame = new QFrame;
                sectionFrame->setStyleSheet(
                    "QFrame#section{border:1px solid "+COLOR_BORDER+";}"
                );
                sectionFrame->setObjectName("section");
                sectionFrame->setMaximumWidth(450);
                sectionFrame->setMinimumWidth(450);

                QVBoxLayout *sectionLayout = new QVBoxLayout;
                QLabel *nameLabel = new QLabel(section.getName());
                nameLabel->setStyleSheet(
                    "color:" + COLOR_TEXT_PRIMARY + ";"
                    "font-size:14px;"
                );
                QLabel *contactNameLabel = new QLabel(section.getContactName());
                contactNameLabel->setStyleSheet(
                    "color:" + COLOR_PRIMARY + ";"
                    "font-size:14px;"
                );
                QLabel *phoneLabel = new QLabel(section.getContact());
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
                sectionLayout->addWidget(nameLabel);
                sectionLayout->addWidget(contactNameLabel);
                sectionLayout->addWidget(phoneLabel);
                sectionFrame->setLayout(sectionLayout);
                sectionContainer->addWidget(sectionFrame);
            }
        }
        mainLayout->addLayout(sectionContainer);
    }

    this->setLayout(mainLayout);
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}
