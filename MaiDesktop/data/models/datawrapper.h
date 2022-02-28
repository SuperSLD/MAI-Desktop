#ifndef DATAWRAPPER_H
#define DATAWRAPPER_H

#include <qstring.h>


/**
 * Общая модель ответа сервера.
 */
template <typename T> class DataWrapper {
private:
    bool success;
    QString message;
    T data;

public:
    DataWrapper(
        bool success,
        QString message,
        T data
    );

    /**
     * @brief isSuccess
     *
     * Проверка валидности ответа
     * сервера.
     *
     * @return true если запрос прошел без ошибок.
     */
    bool isSuccess();

    /**
     * @brief getMessage
     *
     * Ответ сервера в случае ошибки.
     *
     * @return сообщение об ошибке.
     */
    QString getMessage();

    /**
     * @brief getData
     *
     * Получение полезной информации
     * от сервера.
     *
     * @return данные указанного типа.
     */
    T getData();
};

#endif // DATAWRAPPER_H
