#ifndef SPORTITEMWIDGET_H
#define SPORTITEMWIDGET_H

#include <ui/widgets/cardwidget.h>

#include <data/models/sport/sportmodel.h>



class SportItemWidget: public CardWidget {
    Q_OBJECT
public:
    SportItemWidget(SportModel model);
};

#endif // SPORTITEMWIDGET_H
