#ifndef MAINMENUBUTTONWIDGET_H
#define MAINMENUBUTTONWIDGET_H
#include <ui/widgets/cardwidget.h>

#include <QLabel>


class MainMenuButtonWidget: public CardWidget {
    Q_OBJECT
public:
    int code;

    MainMenuButtonWidget(QString icon, QString title, QString description, int code);
    ~MainMenuButtonWidget();

    void setSubtitle(QString subtitle);
private:
    void selfClick();
    QLabel *descriptionLable;

signals:
    void codeClicked(int code);
};

#endif // MAINMENUBUTTONWIDGET_H
