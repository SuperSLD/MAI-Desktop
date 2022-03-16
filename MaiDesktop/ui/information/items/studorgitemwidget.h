#ifndef STUDORGITEMWIDGET_H
#define STUDORGITEMWIDGET_H

#include <ui/widgets/cardwidget.h>

#include <data/models/studorg/studorgmodel.h>

class StudOrgItemWidget : public CardWidget {
    Q_OBJECT
public:
    StudOrgItemWidget(StudOrgModel model);
};

#endif // STUDORGITEMWIDGET_H
