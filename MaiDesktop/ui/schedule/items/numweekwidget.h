#ifndef NUMWEEKWIDGET_H
#define NUMWEEKWIDGET_H

#include <ui/widgets/cardwidget.h>

class NumWeekWidget : public QPushButton {
    Q_OBJECT
public:
    NumWeekWidget(QString numWeek, bool current);
};

#endif // NUMWEEKWIDGET_H
