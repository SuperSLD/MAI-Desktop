#ifndef DATAWRAPPER_H
#define DATAWRAPPER_H

#include <QJsonObject>
#include <qstring.h>


/**
 * Общая модель ответа сервера.
 */
template <typename T> class DataWrapper {
private:
    bool success = false;
    QString message = NULL;
    T data = T(QJsonValue());

public:
    DataWrapper() {}
    DataWrapper(QJsonObject obj, T data = NULL)  {
        this->success = obj["success"].toBool();
        this->message = obj["message"].toString();
        this->data = data;
    }
    ~DataWrapper() {}

    /**
     * @brief isSuccess
     *
     * Проверка валидности ответа
     * сервера.
     *
     * @return true если запрос прошел без ошибок.
     */
    bool isSuccess() {
        return success;
    }


    /**
     * @brief getMessage
     *
     * Ответ сервера в случае ошибки.
     *
     * @return сообщение об ошибке.
     */
    QString getMessage() {
        return message;
    }


    /**
     * @brief getData
     *
     * Получение полезной информации
     * от сервера.
     *
     * @return данные указанного типа.
     */
    T getData() {
        return data;
    }
};

#endif // DATAWRAPPER_H
