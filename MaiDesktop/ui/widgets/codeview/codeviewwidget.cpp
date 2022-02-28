#include "codestyle.h"
#include "codeviewwidget.h"

#include <QRegularExpression>
#include <QTextBrowser>
#include <qboxlayout.h>
#include <qlabel.h>
#include <stylecontainer.h>

using namespace styles;

CodeViewWidget::CodeViewWidget(QString code, CodeStyle* codeStyle) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    inputCode = code;

    QString commentStart = "¤";
    QString commentEnd = "¶";
    QString docCommentStart = "※";
    QString docCommentEnd = "➳";

    QList<QString> symbols = codeStyle->getSymbols();
    symbols.append(" ");
    symbols.append(codeStyle->getStringSymbol());
    symbols.append(commentStart);
    symbols.append(commentEnd);
    symbols.append(docCommentStart);
    symbols.append(docCommentEnd);
    code.replace(codeStyle->getCommentPattern(), commentStart);
    code.replace(codeStyle->getCommentEndPattern(), commentEnd);
    code.replace(codeStyle->getDockCommentPattern(), docCommentStart);
    code.replace(codeStyle->getDockCommentEndPattern(), docCommentEnd);

    QString newCode = "";
    QString word = "";
    bool isString = false;
    bool isComment = false;
    bool isDocComment = false;

    for (int i = 0; i < code.length(); i++) {
        if (!symbols.contains(QString(code[i]))) {
            word += code[i];
        } else {
            QRegExp re("\\d*");
            QString wordColor = "";
            if (isString || isComment) {
                newCode += word;
            } else if (isDocComment) {
                if (word.size() > 0 && word[0] == "@") {
                    wordColor = "#A7CD57";
                }
                newCode += "<font color='"+ wordColor +"'>" + word + "</font>";
            } else {
                if (codeStyle->getKeywords().contains(word)) {
                    wordColor = COLOR_PRIMARY;
                } else if (codeStyle->getOtherKeywords().contains(word)) {
                    wordColor = COLOR_SECONDARY;
                } else if (word.size() > 0 && word[0] == "@") {
                    wordColor = "#FFC062";
                } else if (re.exactMatch(word)) {
                    wordColor = "#85C4FF";
                } else if (code[i] == "(") {
                    wordColor = "#E5AEFF";
                }
                newCode += "<font color='"+ wordColor +"'>" + word + "</font>";
            }
            if (code[i] == "<") { newCode += "&lt;"; }
            else if (code[i] == ">") { newCode += "&gt;"; }
            else if (code[i] == codeStyle->getStringSymbol()) {
                isString = !isString;
                if (isString) {
                    newCode += "<font color='#529474'>" + codeStyle->getStringSymbol();
                } else {
                    newCode += codeStyle->getStringSymbol() + "</font>";
                }
            }
            else if (code[i] == commentStart && !isComment) {
                isComment = true;
                newCode += "<font color='#646464'>" + codeStyle->getCommentPattern();
            }
            else if (code[i] == commentEnd && isComment) {
                isComment = false;
                newCode += codeStyle->getCommentEndPattern() + "</font>";
            }
            else if (code[i] == docCommentStart && !isDocComment) {
                isDocComment = true;
                newCode += "<font color='#519861'>" + codeStyle->getDockCommentPattern();
            }
            else if (code[i] == docCommentEnd && isDocComment) {
                isDocComment = false;
                newCode += codeStyle->getDockCommentEndPattern() + "</font>";
            }
            else if (isComment || isString || isDocComment) {
                newCode += code[i];
            }
            else {
                newCode += "<font color='#C4DBF1'>" + code[i] + "</font>";
            }
            word = "";
        }
    }

    newCode = "<pre><font color='#FFFFFF'>" + newCode + "</font></pre>";
    newCode.replace(commentEnd, codeStyle->getCommentEndPattern());
    newCode.replace(docCommentEnd, codeStyle->getDockCommentEndPattern());

    // заголовок с кружками
    QHBoxLayout *dotsContainer = new QHBoxLayout();
    QWidget *dot1 = new QWidget();
    dot1->setMaximumSize(QSize(12, 12));
    dot1->setMinimumSize(QSize(12, 12));
    dot1->setStyleSheet(
        "background-color:#E4695D;"
        "border-radius:6px;"
    );
    QWidget *dot2 = new QWidget();
    dot2->setMaximumSize(QSize(12, 12));
    dot2->setMinimumSize(QSize(12, 12));
    dot2->setStyleSheet(
        "background-color:#F1BF4F;"
        "border-radius:6px;"
    );
    QWidget *dot3 = new QWidget();
    dot3->setMaximumSize(QSize(12, 12));
    dot3->setMinimumSize(QSize(12, 12));
    dot3->setStyleSheet(
        "background-color:#6CC655;"
        "border-radius:6px;"
    );
    dotsContainer->addWidget(dot1);
    dotsContainer->addWidget(dot2);
    dotsContainer->addWidget(dot3);
    dotsContainer->setAlignment(Qt::AlignLeft);
    dotsContainer->setContentsMargins(16, 16, 16, 0);
    mainLayout->addLayout(dotsContainer);

    // код
    QLabel *codeLable = new QLabel();
    codeLable->setText(newCode);
    codeLable->setStyleSheet(
        "font-size:14px;"
        "background-color:"+COLOR_BACKGROUND+";"
        "border:none;"
    );
    codeLable->setContentsMargins(16, 16, 16, 12);
    codeLable->setWordWrap(true);
    mainLayout->addWidget(codeLable);

    this->setLayout(mainLayout);
    this->setObjectName("sort_item");
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setStyleSheet(
        "QFrame#sort_item {"
        "background-color:"+COLOR_BACKGROUND+";"
        "font-size:16px;"
        "padding: 0px;"
        //"border-radius:8px;"
        "}"
    );
}


QString CodeViewWidget::getCode() {
    return inputCode;
}
