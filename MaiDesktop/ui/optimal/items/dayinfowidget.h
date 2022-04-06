#ifndef DAYINFOWIDGET_H
#define DAYINFOWIDGET_H

#include <QString>

#include <ui/widgets/cardwidget.h>

class DayInfoWidget : public CardWidget {
    Q_OBJECT
public:
    DayInfoWidget(QString dayName, QList<QString> dayTimes, QList<QString> dayPercent, QList<QString> dayCountPeople);
};

#endif // DAYINFOWIDGET_H
