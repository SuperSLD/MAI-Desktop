#include "jsoncodestyle.h"

#include <qlist.h>

JsonCodeStyle::JsonCodeStyle() {}

QString JsonCodeStyle::getName() { return "JSON"; }
QList<QString> JsonCodeStyle::getKeywords() { return { "true", "false", "null" }; }
QList<QString> JsonCodeStyle::getOtherKeywords() { return { "" }; }
QList<QString> JsonCodeStyle::getSymbols() { return { "/", "+", "-", "*",  "%", "^", "<", ">", ",", ".", "=", ";", "{", "}", ":", "(", ")" }; }
QString JsonCodeStyle::getCommentPattern() { return "//"; }
QString JsonCodeStyle::getCommentEndPattern() { return "\n"; }
QString JsonCodeStyle::getStringSymbol() { return "\""; }
QString JsonCodeStyle::getDockCommentPattern() { return "no dok coment"; }
QString JsonCodeStyle::getDockCommentEndPattern() { return "no dok coment"; }
