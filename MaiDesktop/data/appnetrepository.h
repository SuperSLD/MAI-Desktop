#ifndef APPNETREPOSITORY_H
#define APPNETREPOSITORY_H

/**
 * @brief The AppRepository class
 *
 * Репозиторий для получения
 * информации с сервера.
 *
 */
class AppNetRepository {

public:
    AppNetRepository();
    ~AppNetRepository();

    virtual void loadSchedule() {}
};

#endif // APPNETREPOSITORY_H
