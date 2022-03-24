#include "mainmenubuttonwidget.h"

#include <QSvgWidget>
#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

MainMenuButtonWidget::MainMenuButtonWidget(
        QString icon,
        QString title,
        QString description,
        int code
) {
    this->code = code;
    this->setStyleSheet(
            "QFrame#menuButton {"
            "   background-color:#343434;"
            "}"
            "QFrame#menuButton:hover {"
            "   background-color:#3D3D3D;"
            "}"
    );
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setObjectName("menuButton");

    // кнопка
    QVBoxLayout *mainContainer = new QVBoxLayout;
    mainContainer->setContentsMargins(0, 0, 0, 0);
    QPushButton *button = new QPushButton(this);
    button->setStyleSheet("border:none; padding:0px; background-color:#00FFFFFF;");
    connect(button, &QPushButton::clicked, this, &MainMenuButtonWidget::selfClick);
    mainContainer->addWidget(button);
    this->setLayout(mainContainer);

    // контейнер кнопки
    QVBoxLayout *buttonContainer = new QVBoxLayout;
    buttonContainer->setContentsMargins(20, 20, 20, 20);
    button->setLayout(buttonContainer);
    buttonContainer->setContentsMargins(20, 20, 20, 20);
    buttonContainer->setAlignment(Qt::AlignTop);
    button->setMinimumHeight(180);
    //bi->setLayout(buttonContainer);

    QSvgWidget *iconButton = new QSvgWidget(":/resc/resc/"+icon+".svg");
    buttonContainer->addWidget(iconButton);
    iconButton->setMaximumSize(QSize(88,88));
    iconButton->setMinimumSize(QSize(88,88));

    QLabel *titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
    );
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    descriptionLable = new QLabel(description);
    descriptionLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
    );
    descriptionLable->setFont(QFont("Roboto", 14, QFont::Normal));
    buttonContainer->addWidget(titleLabel);
    buttonContainer->addWidget(descriptionLable);

    this->setLayout(mainContainer);
    this->setMinimumHeight(mainContainer->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setMinimumWidth(306);
}

MainMenuButtonWidget::~MainMenuButtonWidget() {
    delete descriptionLable;
}

void MainMenuButtonWidget::selfClick() {
    emit codeClicked(this->code);
}

void MainMenuButtonWidget::setSubtitle(QString subtitle) {
    descriptionLable->setText(subtitle);
}
