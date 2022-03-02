#include "apiservice.h"

#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QList>
#include <QNetworkReply>
#include <QUuid>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include "implfragmentfactory.h"
using namespace screens;
using namespace service;

ApiService::ApiService(AppNetRepository *rep) {
    this->rep = rep;
    networkManager = new QNetworkAccessManager();
    connect(
        networkManager,
        &QNetworkAccessManager::finished,
        this,
        &ApiService::onHttpResult
    );
}

ApiService::~ApiService() {
    delete networkManager;
}


void ApiService::makeRequest(int type, QString url, void (*handler)(QJsonObject, AppNetRepository*), QJsonObject param) {
    qDebug() << "AppNetworkService: make request" << Qt::endl;
    qDebug() << "AppNetworkService: " << url << Qt::endl;
    QNetworkRequest request(QUrl(SERVER_URL + "/" + url));
    request.setHeader(
                QNetworkRequest::ContentTypeHeader,
                QStringLiteral("application/json;charset=utf-8")
    );
    request.setRawHeader("ApiKey", "f723a6fc-09ff-4825-ac05-c1c2f5309d1c");
    HandlerData handlerData = HandlerData();
    handlerData.handler = handler;
    qDebug() << "AppNetworkService: handler UUID -" << handlerData.uuid << Qt::endl;
    handlers.append(handlerData);
    QNetworkReply* reply;
    if (type == POST) {
        qDebug() << "AppNetworkService: POST" << Qt::endl;
        reply = networkManager->post(
            request,
            QJsonDocument(param).toJson(QJsonDocument::Compact)
        );
    } else {
        qDebug() << "AppNetworkService: GET" << Qt::endl;
        reply = networkManager->get(request);
    }
    reply->setProperty("request_id", handlerData.uuid);
}

void ApiService::onHttpResult(QNetworkReply *reply) {
    qDebug() << "AppNetworkService: http response" << Qt::endl;
    QString uuid = reply->property("request_id").toString();
    qDebug() << "AppNetworkService: response UUID -" << uuid << Qt::endl;
    HandlerData handlerData;
    int handlerIndex = -1;
    for (int i = 0; i < handlers.size(); i++) {
        if (handlers[i].uuid == uuid) {
            handlerData = handlers[i];
            handlerIndex = i;
            qDebug() << "AppNetworkService: success found handler -" << uuid << Qt::endl;
        }
    }

    if(!reply->error()) {
        QByteArray resp = reply->readAll();
        qDebug() << "AppNetworkService: " << resp << Qt::endl;
        QJsonDocument doc = QJsonDocument::fromJson(resp);
        QJsonObject obj;
        if(!doc.isNull()) {
            if(doc.isObject()) {
                obj = doc.object();
            } else {
                qDebug() << "AppNetworkService: Document is not an object" << Qt::endl;
            }
        } else {
            qDebug() << "AppNetworkService: Invalid JSON...\n" << Qt::endl;
        }

        qDebug() << "AppNetworkService: success parse -" << uuid << Qt::endl;
        handlerData.handler(obj, rep);

    } else {
        qDebug() << "AppNetworkService: http response error -" << uuid << Qt::endl;
    }

    // удаляем хэндлер запроса если он найден
    if (handlerIndex >= 0) {
        handlers.removeAt(handlerIndex);
        qDebug() << "AppNetworkService: handler remove -" << handlers.size() << Qt::endl;
    }
}
