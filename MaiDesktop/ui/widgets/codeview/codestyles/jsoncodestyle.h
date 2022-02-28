#ifndef JSONCODESTYLE_H
#define JSONCODESTYLE_H

#include <ui/widgets/codeview/codestyle.h>



class JsonCodeStyle : public CodeStyle {
public:
    JsonCodeStyle();

    QString getName() override;
    QList<QString> getKeywords() override;
    QList<QString> getOtherKeywords() override;
    QList<QString> getSymbols() override;
    QString getCommentPattern() override;
    QString getCommentEndPattern() override;
    QString getStringSymbol() override;
    QString getDockCommentPattern() override;
    QString getDockCommentEndPattern() override;
};

#endif // JSONCODESTYLE_H
