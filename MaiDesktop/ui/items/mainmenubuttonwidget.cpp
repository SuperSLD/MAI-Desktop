#include "mainmenubuttonwidget.h"

#include <QSvgWidget>
#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

MainMenuButtonWidget::MainMenuButtonWidget(QString icon, QString title, QString description){
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setAlignment(Qt::AlignTop);
    QSvgWidget *iconButton = new QSvgWidget(":/resc/resc/"+icon+".svg");
    mainLayout->addWidget(iconButton);
    iconButton->setMaximumSize(QSize(88,88));
    iconButton->setMinimumSize(QSize(88,88));

    QLabel *titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:14px;"
    );
    QLabel *descriptionLable = new QLabel(description);
    descriptionLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:14px;"
    );
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(descriptionLable);

    this->setLayout(mainLayout);
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setMinimumWidth(306);
}
