#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QFrame>


/**
 * @brief The ToolbarWidget class
 *
 * Тулбар. Верхний элемент экрана
 * с заголовком и парой кнопок.
 */
class ToolbarWidget: public QFrame {
    Q_OBJECT
private:
    QString title;
public:
    /**
     * @brief ToolbarWidget
     *
     * Конструктор тулбара.
     * На вход подается три параметра, из которых
     * обязателен тольео один - title.

     * @param title название экрана которое увидит пользователь.
     * @param showBack если true то на тулбаре есть стрелка назад.
     * @param icon иконка для кнопки справа тулбара.
     */
    ToolbarWidget(QString title, bool showBack = false, QString icon = "");
    ~ToolbarWidget();
signals:
    /**
     * @brief onBackPressed
     *
     * Если у тулбара есть кнопка "Назад",
     * то при нажатии на нее вызовется
     * этот сигнал.
     */
    void onBackPressed();

    /**
     * @brief onButtinPressed
     *
     * Если у тулбара есть кнопка справа,
     * то при нажатии на нее вызовется
     * этот сигнал.
     */
    void onButtinPressed();
};

#endif // TOOLBARWIDGET_H
