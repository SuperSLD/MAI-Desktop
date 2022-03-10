#include "loadingcontainerwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>
#include <qsvgwidget.h>
#include <stylecontainer.h>
using namespace styles;

LoadingContainerWidget::LoadingContainerWidget(QFrame *content) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // контейнер для кружка
    QFrame *loading = new QFrame;
    QVBoxLayout*loadingLayout = new QVBoxLayout;
    loadingLayout->setAlignment(Qt::AlignCenter);
    loadingLable = new QLabel("Загрузка");
    loadingLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:18px;"
        //"background-color:#0000FF;"
    );
    QWidget *loaderBox = new QWidget;
    loaderBox->setMinimumSize(QSize(600, 80));
    loaderBox->setMaximumSize(QSize(600, 80));
    loader = new WaitingSpinnerWidget(loaderBox, true, false);
    loadingLable->setMinimumWidth(600);
    loadingLable->setMaximumWidth(600);
    loadingLable->setAlignment(Qt::AlignHCenter);
    loader->setColor(QT_COLOR_PRIMARY);
    loadingLayout->addWidget(loaderBox);
    loadingLayout->addWidget(loadingLable);
    loading->setLayout(loadingLayout);

    // контейнер для кружка
    QFrame *error = new QFrame;
    QVBoxLayout*errorLayout = new QVBoxLayout;
    errorLayout->setAlignment(Qt::AlignCenter);
    errorLable = new QLabel("Загрузка");
    errorLable->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:18px;"
        //"background-color:#0000FF;"
    );
    QSize size(96, 96);
    QHBoxLayout *imageContainer = new QHBoxLayout;
    QSvgWidget *image = new QSvgWidget(":/resc/resc/clear.svg");
    image->setMaximumSize(size);
    image->setMinimumSize(size);
    imageContainer->addWidget(image);
    imageContainer->setAlignment(Qt::AlignCenter);
    errorLable->setMinimumWidth(600);
    errorLable->setAlignment(Qt::AlignHCenter);
    errorLable->setMaximumWidth(600);
    errorLayout->addLayout(imageContainer);
    errorLayout->addWidget(errorLable);
    error->setLayout(errorLayout);


    stack = new QStackedWidget;
    stack->addWidget(loading);
    stack->addWidget(content);
    stack->addWidget(error);
    stack->setCurrentIndex(0);
    mainLayout->addWidget(stack);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mainLayout);
}

LoadingContainerWidget::~LoadingContainerWidget() {
    delete stack;
}

void LoadingContainerWidget::startLoading(QString message) {
    this->message = message;
    loader->start();
    loadingLable->setText(message);
    stack->setCurrentIndex(0);
}

void LoadingContainerWidget::stopLoading() {
    stack->setCurrentIndex(1);
    loader->stop();
}

void LoadingContainerWidget::error(QString message) {
    stack->setCurrentIndex(2);
    loader->stop();
    errorLable->setText(message);
}
