#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QJsonObject>


/**
 * @brief The BaseModel class
 *
 * Базовая модель объекта,
 * от которого наследуются все
 * другие объекты, передающиеся
 * между экранами.
 *
 */
class BaseModel {

public:
    BaseModel(QJsonObject obj);
    virtual void pol();
};

#endif // BASEMODEL_H
