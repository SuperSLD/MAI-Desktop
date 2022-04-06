#include "groupitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

#include <stylecontainer.h>
using namespace styles;

GroupItemWidget::GroupItemWidget(GroupModel model) {
    this->model = model;

    // кнопка
    QVBoxLayout *mainContainer = new QVBoxLayout;
    mainContainer->setContentsMargins(0, 0, 0, 0);
    QPushButton *button = new QPushButton(this);
    button->setStyleSheet("border:none; padding:0px; background-color:#00FFFFFF;");
    connect(button, &QPushButton::clicked, this, &GroupItemWidget::selfClick);
    mainContainer->addWidget(button);

    // контейнер кнопки
    QVBoxLayout *buttonContainer = new QVBoxLayout;
    buttonContainer->setContentsMargins(20, 20, 20, 20);
    button->setLayout(buttonContainer);
    buttonContainer->setContentsMargins(20, 20, 20, 20);
    buttonContainer->setAlignment(Qt::AlignTop);
    button->setMinimumHeight(90);
    //bi->setLayout(buttonContainer);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
    );
    titleLabel->setFont(QFont("Roboto", 24, QFont::Normal));
    QLabel *instLable = new QLabel(model.getFaculty());
    instLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
    );
    instLable->setFont(QFont("Roboto", 14, QFont::Normal));
    QLabel *yearLable = new QLabel("Курс " + QString::number(model.getCourse()));
    yearLable->setStyleSheet(
        "color:" + COLOR_PRIMARY+ ";"
        "font-size:14px;"
    );
    yearLable->setFont(QFont("Roboto", 14, QFont::Normal));
    buttonContainer->addWidget(titleLabel);

    QHBoxLayout *infoContainer = new QHBoxLayout;
    infoContainer->addWidget(instLable);
    infoContainer->addWidget(yearLable);
    infoContainer->setAlignment(Qt::AlignLeft);
    buttonContainer->addLayout(infoContainer);

    this->setLayout(mainContainer);
    this->setObjectName("group");
    this->setMinimumHeight(mainContainer->geometry().height());
    this->setStyleSheet(
                "QFrame#group{"
                "border: 1px solid "+COLOR_BORDER+";}"
    );
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}

void GroupItemWidget::selfClick() {
    emit groupClicked(model.clone());
}
