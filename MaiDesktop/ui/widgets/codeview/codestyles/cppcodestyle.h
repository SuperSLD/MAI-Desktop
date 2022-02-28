#ifndef CPPCODESTYLE_H
#define CPPCODESTYLE_H

#include <ui/widgets/codeview/codestyle.h>



class CppCodeStyle : public CodeStyle {
public:
    CppCodeStyle();

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

#endif // CPPCODESTYLE_H
