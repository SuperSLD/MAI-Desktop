#ifndef CODESTYLE_H
#define CODESTYLE_H

#include <QString>


/**
 * @brief CodeStyle::CodeStyle
 *
 * Описание языка програмирования.
 *
 */
class CodeStyle {
public:
    CodeStyle();

    virtual QString getName();
    virtual QList<QString> getKeywords();
    virtual QList<QString> getOtherKeywords();
    virtual QList<QString> getSymbols();
    virtual QString getCommentPattern();
    virtual QString getCommentEndPattern();
    virtual QString getStringSymbol();
    virtual QString getDockCommentPattern();
    virtual QString getDockCommentEndPattern();
};

#endif // CODESTYLE_H
