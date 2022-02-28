#include "cppcodestyle.h"

#include <qlist.h>

CppCodeStyle::CppCodeStyle() {}
QString CppCodeStyle::getName() { return "C++"; }
QList<QString> CppCodeStyle::getKeywords() { return { "do", "if", "and", "asm", "for", "int", "new", "not", "try", "xor", "auto", "bool", "case", "char", "else", "enum", "goto", "long", "this", "true", "void", "bitor", "break", "catch", "class", "compl", "const", "false", "float", "or_eq", "short", "throw", "union", "using", "while", "and_eq", "bitand", "delete", "double", "export", "extern", "friend", "inline", "not_eq", "public", "return", "signed", "sizeof", "static", "struct", "switch", "typeid", "xor_eq", "alignas", "alignof", "default", "mutable", "nullptr", "private", "typedef", "virtual", "wchar_t", "char16_t", "char32_t", "continue", "decltype", "explicit", "noexcept", "operator", "register", "template", "typename", "unsigned", "volatile", "constexpr", "namespace", "protected", "const_cast", "static_cast", "dynamic_cast", "thread_local", "static_assert", "reinterpret_cast" }; }
QList<QString> CppCodeStyle::getOtherKeywords() { return { "QList", "QString", "signal", "slot", "std::", "Q_OBJECT", "qDebug", "connect", "disconnect", "QHBoxLayout", "QVBoxLayout", "Qt", "QWidget" }; }
QList<QString> CppCodeStyle::getSymbols() { return { "/", "+", "-", "*",  "%", "^", "<", ">", ",", ".", "=", ";", "{", "}", ":", "(", ")" }; }
QString CppCodeStyle::getCommentPattern() { return "//"; }
QString CppCodeStyle::getCommentEndPattern() { return "\n"; }
QString CppCodeStyle::getStringSymbol() { return "\""; }
QString CppCodeStyle::getDockCommentPattern() { return "/**"; }
QString CppCodeStyle::getDockCommentEndPattern() { return "*/"; }
