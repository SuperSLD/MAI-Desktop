#include "menubuttonwidget.h"

#include <stylecontainer.h>
using namespace styles;

#include <Qt>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qsvgwidget.h>

MenuButtonWidget::MenuButtonWidget(QString title, QString icon, int code) {
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
    this->setMinimumHeight(71);
    this->setObjectName("menuButton");

    // кнопка
    QVBoxLayout *mainContainer = new QVBoxLayout;
    mainContainer->setContentsMargins(0, 0, 0, 0);
    QPushButton *button = new QPushButton(this);
    button->setStyleSheet("border:none; padding:0px; background-color:#00FFFFFF;");
    connect(button, &QPushButton::clicked, this, &MenuButtonWidget::selfClick);
    mainContainer->addWidget(button);
    button->setMinimumHeight(71);
    this->setLayout(mainContainer);

    // контейнер кнопки
    QHBoxLayout *buttonContainer = new QHBoxLayout;
    buttonContainer->setContentsMargins(20, 20, 20, 20);
    button->setLayout(buttonContainer);
    //bi->setLayout(buttonContainer);

    QSvgWidget *image = new QSvgWidget(":/resc/resc/"+icon+".svg");
    QSize size(32, 32);
    image->setMaximumSize(size);
    image->setMinimumSize(size);
    buttonContainer->addWidget(image);

    // заголовок кнопки
    QLabel *titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
        "font-size:18px;"
    );
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    titleLabel->setContentsMargins(16, 0, 0, 0);
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    buttonContainer->addWidget(titleLabel);

}

void MenuButtonWidget::selfClick() {
    emit codeClicked(this->code);
}
