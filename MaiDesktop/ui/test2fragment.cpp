#include "test2fragment.h"

#include <QLabel>

Test2Fragment::Test2Fragment() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;


    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    // тестовый лэйбл
    QLabel * testText = new QLabel("hello world 2!!!!");
    mainHLayout->addWidget(testText);

    this->setLayout(mainVLayout);
}
