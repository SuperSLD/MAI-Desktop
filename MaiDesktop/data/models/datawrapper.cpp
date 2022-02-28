#include "datawrapper.h"

template <typename  T> DataWrapper<T>::DataWrapper(
    bool success,
    QString message,
    T data
) {
    this->success = success;
    this->message = message;
    this->data = data;
}

template <typename  T> bool DataWrapper<T>::isSuccess() {
    return success;
}

template <typename  T> QString DataWrapper<T>::getMessage() {
    return message;
}

template <typename  T> T DataWrapper<T>::getData() {
    return data;
}
