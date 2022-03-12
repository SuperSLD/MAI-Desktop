#ifndef MENUBUTTONWIDGET_H
#define MENUBUTTONWIDGET_H

#include <QObject>
#include <QPushButton>
#include <QWidget>

#include <ui/widgets/cardwidget.h>

class MenuButtonWidget: public CardWidget {
    Q_OBJECT
public:
    int code;

    MenuButtonWidget(QString title, QString icon, int code = -1);

private:
    void selfClick();
signals:
    void codeClicked(int code);

};

#endif // MENUBUTTONWIDGET_H
