#include "columnwidget.h"

#include <QHBoxLayout>
#include <QDebug>

#include <stylecontainer.h>
using namespace styles;

ColumnWidget::ColumnWidget(float percent) {
    this->setFixedHeight(202);
    this->setFixedWidth(147);

    this->setStyleSheet(
        "background-color:" + COLOR_BORDER + ";"
        "border:none;"
        "padding:0px;"
    );

    // Основное расположение элементов в окне
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setMargin(7);
    mainVLayout->setAlignment(Qt::AlignBottom);    // направление выравнивания (наверх)
    this->setLayout(mainVLayout);   // назначение главного лейута

    QFrame *percentFrame = new QFrame;
    percentFrame->setFixedWidth(133);
    percentFrame->setFixedHeight(static_cast<int>(202*(percent/100)));
    percentFrame->setStyleSheet(
        "background-color:" + COLOR_PRIMARY + ";"
    );
    mainVLayout->addWidget(percentFrame);
}
