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

ApiService::ApiService(AppNetRepository *rep, bool debug) {
    this->rep = rep;
    this->debug = debug;
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

QNetworkRequest ApiService::createRequest(QString url) {
    qDebug() << "AppNetworkService: make request";
    qDebug() << "AppNetworkService: " << SERVER_URL + "/" + url;
    QNetworkRequest request(QUrl(SERVER_URL + "/" + url));
    request.setHeader(
                QNetworkRequest::ContentTypeHeader,
                QStringLiteral("application/json;charset=utf-8")
    );
    request.setRawHeader("ApiKey", "f723a6fc-09ff-4825-ac05-c1c2f5309d1c");
    return request;
}

QString ApiService::createResponseHandler(void (*handler)(QJsonObject, AppNetRepository*)) {
    HandlerData handlerData = HandlerData();
    handlerData.handler = handler;
    qDebug() << "AppNetworkService: handler UUID -" << handlerData.uuid;
    handlers.append(handlerData);
    return handlerData.uuid;
}

void ApiService::get(QString url, void (*handler)(QJsonObject, AppNetRepository*)) {
    QNetworkRequest req = createRequest(url);
    QString uuid = createResponseHandler(handler);
    QNetworkReply* reply;
    qDebug() << "AppNetworkService: GET" << uuid;
    reply = networkManager->get(req);
    reply->setProperty("request_id", uuid);
}


void ApiService::post(QString url, void (*handler)(QJsonObject, AppNetRepository*),  QJsonObject param) {
    QNetworkRequest req = createRequest(url);
    QString uuid = createResponseHandler(handler);
    QNetworkReply* reply;
    qDebug() << "AppNetworkService: POST" << uuid;
    qDebug() << "AppNetworkService: BODY-" << QJsonDocument(param).toJson(QJsonDocument::Compact) << Qt::endl << "BODY uuid-" << uuid << Qt::endl;
    reply = networkManager->post(
        req, QJsonDocument(param).toJson(QJsonDocument::Compact)
    );
    reply->setProperty("request_id", uuid);
}

void ApiService::onHttpResult(QNetworkReply *reply) {
    QString uuid = reply->property("request_id").toString();
    qDebug() << "AppNetworkService: response UUID -" << uuid;
    HandlerData handlerData;
    int handlerIndex = -1;
    QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if ( statusCode.isValid() ) {
        qDebug() << "AppNetworkService: STATUS CODE -" << statusCode.toString() << uuid;
    }
    for (int i = 0; i < handlers.size(); i++) {
        if (handlers[i].uuid == uuid) {
            handlerData = handlers[i];
            handlerIndex = i;
            qDebug() << "AppNetworkService: success found handler -" << uuid;
        }
    }

    QJsonObject errorResponse;
    errorResponse.insert("success", false);

    if(!reply->error()) {
        QByteArray resp = reply->readAll();
        if (debug) qDebug() << "AppNetworkService: " << resp << uuid;
        QJsonDocument doc = QJsonDocument::fromJson(resp);
        QJsonObject obj;
        if(!doc.isNull()) {
            if(doc.isObject()) {
                obj = doc.object();
                qDebug() << "AppNetworkService: success parse -" << uuid;
                handlerData.handler(obj, rep);
            } else {
               qDebug() << "AppNetworkService: Document is not an object" << uuid;
               errorResponse.insert("message", "Неправильный ответ сервера");
               handlerData.handler(errorResponse, rep);
            }
        } else {
            qDebug() << "AppNetworkService: Invalid JSON...\n" << uuid;
            errorResponse.insert("message", "Неправильный ответ сервера");
            handlerData.handler(errorResponse, rep);
        }
    } else {
        qDebug() << "AppNetworkService: http response error -" << uuid;
        errorResponse.insert("message", "Ошибка подключения");
        handlerData.handler(errorResponse, rep);

    }

    // удаляем хэндлер запроса если он найден
    if (handlerIndex >= 0) {
        handlers.removeAt(handlerIndex);
        qDebug() << "AppNetworkService: handler remove -" << handlers.size();
    }
}
