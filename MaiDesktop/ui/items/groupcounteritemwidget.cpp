#include "groupcounteritemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

#include <stylecontainer.h>
using namespace styles;

GroupCounterItemWidget::GroupCounterItemWidget(GroupModel *model) {
    this->model = model;

    // кнопка
    QHBoxLayout *counterContainer = new QHBoxLayout;
    QVBoxLayout *mainContainer = new QVBoxLayout;
    counterContainer->setContentsMargins(20, 20, 20, 20);
    counterContainer->addLayout(mainContainer);

    QLabel *titleLabel = new QLabel(model->getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_PRIMARY + ";"
    );
    titleLabel->setFont(QFont("Roboto", 24, QFont::Normal));
    QLabel *instLable = new QLabel(model->getFaculty());
    instLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
    );
    instLable->setFont(QFont("Roboto", 14, QFont::Normal));
    QLabel *yearLable = new QLabel("Курс " + QString::number(model->getCourse()));
    yearLable->setStyleSheet(
        "color:" + COLOR_PRIMARY+ ";"
        "font-size:14px;"
    );
    yearLable->setFont(QFont("Roboto", 14, QFont::Normal));
    mainContainer->addWidget(titleLabel);

    QHBoxLayout *infoContainer = new QHBoxLayout;
    infoContainer->addWidget(instLable);
    infoContainer->addWidget(yearLable);
    infoContainer->setAlignment(Qt::AlignLeft);
    mainContainer->addLayout(infoContainer);

    QHBoxLayout *counterButtonsContainer = new QHBoxLayout;
    counterContainer->addLayout(counterButtonsContainer);

    QSize butttonSize = QSize(30, 30);
    QSize labelSize = QSize(50, 30);

    // Кнопка с плюсом
    QPushButton *minusButton = new QPushButton("-");
    minusButton->setStyleSheet(BUTTON_SOLID);
    minusButton->setMinimumSize(butttonSize);
    minusButton->setMaximumSize(butttonSize);
    connect(minusButton, &QPushButton::clicked, this, &GroupCounterItemWidget::minusCount);

    if (model->count == 0) model->count = 1;

    // Количество
    counterLabel = new QLabel(QString::number(model->count));
    counterLabel->setStyleSheet(
                "QLabel {"
                "   background-color:"+COLOR_BORDER+";"
                "   font-size:16px;"
                "   padding: 8px;"
                "   border-radius:0px;"
                "   color:"+COLOR_TEXT_PRIMARY+";"
                "}"
    );
    counterLabel->setMinimumSize(labelSize);
    counterLabel->setMaximumSize(labelSize);
    counterLabel->setAlignment(Qt::AlignCenter);


    // Кнопка с минусом
    QPushButton *plusButton = new QPushButton("+");
    plusButton->setStyleSheet(BUTTON_SOLID);
    plusButton->setMinimumSize(butttonSize);
    plusButton->setMaximumSize(butttonSize);
    connect(plusButton, &QPushButton::clicked, this, &GroupCounterItemWidget::plusCount);

    counterButtonsContainer->addWidget(minusButton);
    counterButtonsContainer->addWidget(counterLabel);
    counterButtonsContainer->addWidget(plusButton);

    this->setLayout(counterContainer);
    this->setObjectName("group");
    this->setMinimumHeight(counterContainer->geometry().height());
    this->setStyleSheet(
                "QFrame#group{"
                "border: 1px solid "+COLOR_BORDER+";}"
    );
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}

GroupCounterItemWidget::~GroupCounterItemWidget() {
    delete counterLabel;
}

void GroupCounterItemWidget::minusCount() {
    model->count--;
    counterLabel->setText(QString::number(model->count));
    emit counterUpdated();
}

void GroupCounterItemWidget::plusCount() {
    model->count++;
    counterLabel->setText(QString::number(model->count));
    emit counterUpdated();
}
