#ifndef GROUPITEMWIDGET_H
#define GROUPITEMWIDGET_H

#include <data/models/group/groupmodel.h>

#include <qframe.h>



class GroupItemWidget : public QFrame {
    Q_OBJECT

private:
    GroupModel model = GroupModel(
        "123", "123", "123", "123", 0
    );

public:
    GroupItemWidget(GroupModel model);

private slots:
    void selfClick();

signals:
    void groupClicked(GroupModel model);
};

#endif // GROUPITEMWIDGET_H
