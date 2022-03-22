#ifndef CREATIVEITEMWIDGET_H
#define CREATIVEITEMWIDGET_H

#include <ui/widgets/cardwidget.h>

#include <data/models/creative/creativemodel.h>



class CreativeItemWidget : public CardWidget {
    Q_OBJECT
public:
    CreativeItemWidget(CreativeModel model);
};

#endif // CREATIVEITEMWIDGET_H
