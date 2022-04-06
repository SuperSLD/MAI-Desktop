#include "creativeitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

CreativeItemWidget::CreativeItemWidget(CreativeModel model) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setAlignment(Qt::AlignTop);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_PRIMARY + ";"
    );
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    QHBoxLayout *contactContainer = new QHBoxLayout;
    QLabel *nameLabel = new QLabel(model.getContactName());
    nameLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    nameLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    QLabel *phoneLable = new QLabel(model.getContact());
    phoneLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:14px;"
    );
    contactContainer->addWidget(nameLabel);
    contactContainer->addWidget(phoneLable);
    contactContainer->setAlignment(Qt::AlignLeft);
    QLabel *descriptionTitleLabel = new QLabel("Описание:");
    descriptionTitleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY+ ";"
        "font-size:14px;"
    );
    descriptionTitleLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    QLabel *descriptionLable = new QLabel("\n" + model.getDescription() + "\n");
    descriptionLable->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    descriptionLable->setFont(QFont("Roboto", 14, QFont::Normal));
    descriptionLable->setWordWrap(true);
    descriptionLable->setMaximumWidth(900);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(contactContainer);
    mainLayout->addWidget(descriptionTitleLabel);
    mainLayout->addWidget(descriptionLable);

    this->setLayout(mainLayout);
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}
