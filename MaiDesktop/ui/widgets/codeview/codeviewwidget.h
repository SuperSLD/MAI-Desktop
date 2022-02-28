#ifndef CODEVIEWWIDGET_H
#define CODEVIEWWIDGET_H

#include "codestyle.h"

#include <QFrame>
#include <QList>

/**
 * @brief The CodeViewWidget class
 *
 * Виджет для отображения кусков
 * кода на разных языках програмирования.
 * Также есть простой способ добавления своего языка.
 */
class CodeViewWidget : public QFrame {
    Q_OBJECT
private:
    QString inputCode = "";

public:
    CodeViewWidget(QString code, CodeStyle* codeStyle);

    /**
     * @brief getCode
     *
     * Получение кода, отображаемого
     * виджетом.
     *
     * @return код
     */
    QString getCode();
};

#endif // CODEVIEWWIDGET_H
