#ifndef GROUPCOUNTERITEMWIDGET_H
#define GROUPCOUNTERITEMWIDGET_H

#include <qframe.h>
#include <qlabel.h>

#include <data/models/group/groupmodel.h>



class GroupCounterItemWidget: public QFrame {
    Q_OBJECT

private:
    GroupModel *model;
    QLabel *counterLabel;

public:
    GroupCounterItemWidget(GroupModel *model);
    ~GroupCounterItemWidget();

private slots:
    void minusCount();
    void plusCount();

signals:
    void counterUpdated();
};

#endif // GROUPCOUNTERITEMWIDGET_H
