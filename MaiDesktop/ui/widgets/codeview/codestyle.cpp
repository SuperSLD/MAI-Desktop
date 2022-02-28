#include "codestyle.h"

#include <QList>


CodeStyle::CodeStyle() {

}

QString CodeStyle::getName() {return "";}
QList<QString> CodeStyle::getKeywords() { return QList<QString>(); }
QList<QString> CodeStyle::getOtherKeywords() { return QList<QString>(); }
QList<QString> CodeStyle::getSymbols() { return QList<QString>(); }
QString CodeStyle::getCommentPattern() { return ""; }
QString CodeStyle::getCommentEndPattern() { return ""; }
QString CodeStyle::getStringSymbol() { return ""; }
QString CodeStyle::getDockCommentPattern() { return ""; }
QString CodeStyle::getDockCommentEndPattern() { return ""; }
