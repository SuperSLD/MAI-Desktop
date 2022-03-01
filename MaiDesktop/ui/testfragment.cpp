#include "testfragment.h"

#include <QLabel>

TestFragment::TestFragment() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;


    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    // тестовый лэйбл
    QLabel * testText = new QLabel("hello world");
    mainHLayout->addWidget(testText);

    this->setLayout(mainVLayout);
}

TestFragment::~TestFragment() {

}
