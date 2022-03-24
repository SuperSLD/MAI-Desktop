#include "libraryitemwidget.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

LibraryItemWidget::LibraryItemWidget(LibraryModel model) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setAlignment(Qt::AlignTop);

    QLabel *titleLabel = new QLabel(model.getName());
    titleLabel->setStyleSheet(
        "color:" + COLOR_PRIMARY + ";"
        "font-size:18px;"
    );
    titleLabel->setFont(QFont("Roboto", 18, QFont::Normal));
    mainLayout->addWidget(titleLabel);

    foreach(LibrarySectionModel section, model.getSections()) {
        QHBoxLayout *sectionContainer = new QHBoxLayout;
        QLabel *nameLabel = new QLabel(section.getName());
        nameLabel->setStyleSheet(
            "color:" + COLOR_TEXT_PRIMARY + ";"
            "font-size:14px;"
        );
        nameLabel->setFont(QFont("Roboto", 14, QFont::Normal));
        QLabel *roomLable = new QLabel(section.getLocation());
        roomLable->setStyleSheet(
            "color:" + COLOR_TEXT_SECONDARY + ";"
            "font-size:14px;"
        );
        roomLable->setFont(QFont("Roboto", 14, QFont::Normal));
        roomLable->setAlignment(Qt::AlignRight);
        sectionContainer->addWidget(nameLabel);
        sectionContainer->addWidget(roomLable);
        QWidget *line = new QWidget;
        line->setStyleSheet(
                    "background-color:"+COLOR_BORDER
        );
        line->setMaximumHeight(1);
        line->setMinimumHeight(1);
        mainLayout->addLayout(sectionContainer);
        mainLayout->addWidget(line);
    }

    this->setLayout(mainLayout);
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}
