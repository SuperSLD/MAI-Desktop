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

namespace service {
    static const int GET = 0;
    static const int POST = 1;
};

class HandlerData;

class ApiService : public QObject {
    Q_OBJECT

private:
    QNetworkAccessManager *networkManager;
    QList<HandlerData> handlers;
    AppNetRepository *rep;

public:
    ApiService(AppNetRepository *rep);
    ~ApiService();

    void makeRequest(
            int type,
            QString url,
            void (*handler)(QJsonObject, AppNetRepository*),
            QJsonObject param = QJsonObject()
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
