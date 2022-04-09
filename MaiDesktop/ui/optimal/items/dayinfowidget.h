#ifndef DAYINFOWIDGET_H
#define DAYINFOWIDGET_H

#include <QString>

#include <ui/widgets/cardwidget.h>
#include <data/models/optimal/optimaldaymodel.h>

class DayInfoWidget : public CardWidget {
    Q_OBJECT
public:
    DayInfoWidget(OptimalDayModel *dayInfo);
};

#endif // DAYINFOWIDGET_H
