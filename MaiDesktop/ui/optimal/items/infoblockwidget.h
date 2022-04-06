#ifndef INFOBLOCKWIDGET_H
#define INFOBLOCKWIDGET_H

#include <ui/widgets/cardwidget.h>

class InfoBlockWidget : public QPushButton {
    Q_OBJECT
public:
    InfoBlockWidget(QString bigName, QString littleName, QString nameColor);
};

#endif // INFOBLOCKWIDGET_H
