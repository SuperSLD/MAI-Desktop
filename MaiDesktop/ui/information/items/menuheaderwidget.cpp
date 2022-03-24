#include "menuheaderwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>
#include <stylecontainer.h>
using namespace styles;

MenuHeaderWidget::MenuHeaderWidget(QString title) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    QLabel *titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(
        "color:" + COLOR_TEXT_SECONDARY + ";"
        "font-size:18px;"
    );
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    mainLayout->addWidget(titleLabel);
    this->setLayout(mainLayout);
}
