#ifndef APISERVICE_H
#define APISERVICE_H

#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QList>
#include <QNetworkReply>
#include <QUuid>
#include <QJsonObject>

class AppNetRepository;
class HandlerData;

class ApiService : public QObject {
    Q_OBJECT

private:
    QNetworkAccessManager *networkManager;
    QList<HandlerData> handlers;
    AppNetRepository *rep;

    /**
     * @brief createRequest
     *
     * Создание запроса для сервера.
     *
     * @param url путь
     * @return реквест для отправки.
     */
    QNetworkRequest createRequest(QString url);

    /**
     * @brief createResponseHandler
     *
     * Создание колбэка, который
     * будет ждать ответ сервера.
     *
     * @return UUID колбэка.
     */
    QString createResponseHandler(void (*handler)(QJsonObject, AppNetRepository*));

public:
    ApiService(AppNetRepository *rep);
    ~ApiService();

    void get(
        QString url,
        void (*handler)(QJsonObject, AppNetRepository*)
    );

    void post(
        QString url,
        void (*handler)(QJsonObject, AppNetRepository*),
        QJsonObject param
    );

private slots:
    void onHttpResult(QNetworkReply *reply);
};


class HandlerData {
    public:
        QString uuid = QUuid::createUuid().toString();
        void (*handler)(QJsonObject, AppNetRepository*);
};

#endif // APISERVICE_H
