//
// Created by ihb on 20.02.17.
//


#include "MainWindow.h"
#include "Canvas.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    god = new God(new Canvas(this));

    showMaximized();

    mainLayout = new QVBoxLayout(this);


    generate = new QPushButton("generate dots", this);
    connect(generate, SIGNAL(clicked()), this, SLOT(onGenerateClicked()));

    bottomLayout = new QHBoxLayout(this);
    bottomLayout->addWidget(generate);




    mainLayout->addWidget(god->getCanvas());
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

void MainWindow::onGenerateClicked() {
    god->generate(100);
}
