#include "searchgroupfragment.h"

#include <QSvgWidget>
#include <qlabel.h>
#include <qpushbutton.h>

#include <stylecontainer.h>
#include <implfragmentfactory.h>
#include <QCoreApplication>
#include <QDateTime>

#include <ui/widgets/codeview/codeviewwidget.h>

#include <ui/widgets/codeview/codestyles/cppcodestyle.h>
#include <ui/widgets/codeview/codestyles/jsoncodestyle.h>


using namespace screens;
using namespace styles;

SearchGroupFragment::SearchGroupFragment() {
    // главный контейнер
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    // отображение исходного кода
    mainVLayout->addWidget(new CodeViewWidget(
        "/**\n"
        "  * Документирующий коментарий, со\n"
        "  * своими правилами выделения слов.\n"
        "  *\n"
        "  * @param параметров нет\n"
        "  * @return функция ничего не возвращает\n"
        "  * @author Leonid Solyanoj (solyanoj.leonid@gmail.com)\n"
        "  */\n"
        "@RequestMapping(\"api/hello\")\n"
        "void Router::removeOnRoot() {\n"
        "   // Отключаем слот от прослушивания завершения анимации \n"
        "   disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnRoot);\n"
        "   BaseFragment* last = stack.last();\n"
        "   // Отчищаем список \n"
        "   stack.clear();\n"
        "   // Отчищаем стак виджет \n"
        "   for(int i = 0; i <= currentContainer->count()-1; i++) {\n"
        "       QWidget* widget = currentContainer->widget(i);\n"
        "       currentContainer->removeWidget(widget);\n"
        "       widget->deleteLater();\n"
        "   }\n"
        "   stack.append(last);\n"
        "   // просто строка, чтоб понтануться выделением текста\n"
        "   QString helloString = \"Hello world! !@#$%^&*(\\n\"\n"
        "}",
        new CppCodeStyle()
    ));

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}

SearchGroupFragment::~SearchGroupFragment() {

}
