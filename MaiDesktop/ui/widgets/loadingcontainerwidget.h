#ifndef LOADINGCONTAINERWIDGET_H
#define LOADINGCONTAINERWIDGET_H

#include "waitingspinnerwidget.h"

#include <QFrame>
#include <QStackedWidget>
#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>

/**
 * @brief The LoadingContainerWidget class
 *
 * Контейнер для отображения лоадеров.
 * Скрывает часть экрана и заменяет ее кружком
 * с загрузкой.
 *
 */
class LoadingContainerWidget : public QFrame {
    Q_OBJECT

private:
    QString message;
    QStackedWidget *stack;
    QLabel *loadingLable;
    WaitingSpinnerWidget *loader;

public:
    LoadingContainerWidget(QFrame *content);
    ~LoadingContainerWidget();

    /**
     * @brief showLoading
     *
     * Отображение загрузки.
     *
     * @param message сообщение, которое увидит пользователь.
     */
    void startLoading(QString message = "Загрузка...");

    /**
     * @brief stopLoading
     *
     * Завершение загрузки, и отображение
     * основного контента.
     *
     */
    void stopLoading();
};

#endif // LOADINGCONTAINERWIDGET_H
