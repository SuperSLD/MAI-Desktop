#ifndef MAINMENUBUTTONWIDGET_H
#define MAINMENUBUTTONWIDGET_H
#include <ui/widgets/cardwidget.h>


class MainMenuButtonWidget: public CardWidget {
    Q_OBJECT
public:
    MainMenuButtonWidget(QString icon, QString title, QString description);
};

#endif // MAINMENUBUTTONWIDGET_H
