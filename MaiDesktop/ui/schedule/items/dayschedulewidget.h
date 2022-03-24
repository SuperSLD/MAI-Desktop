#ifndef DAYSCHEDULEWIDGET_H
#define DAYSCHEDULEWIDGET_H

#include <ui/widgets/cardwidget.h>

#include <data/models/schedule/daymodel.h>

class DayScheduleWidget : public CardWidget {
    Q_OBJECT
private:
    QString date;
    QString name;
public:
    DayScheduleWidget(DayModel countItems);
};

#endif // DAYSCHEDULEWIDGET_H
