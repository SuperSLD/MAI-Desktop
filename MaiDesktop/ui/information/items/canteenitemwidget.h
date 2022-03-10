#ifndef CANTEENITEMWIDGET_H
#define CANTEENITEMWIDGET_H

#include <ui/widgets/cardwidget.h>

#include <data/models/canteens/canteenmodel.h>



class CanteenItemWidget : public CardWidget {
    Q_OBJECT
public:
    CanteenItemWidget(CanteenModel model);
};

#endif // CANTEENITEMWIDGET_H
