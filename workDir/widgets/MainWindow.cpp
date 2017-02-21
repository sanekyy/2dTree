//
// Created by ihb on 20.02.17.
//


#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    god = new God();

    showMaximized();

    mainLayout = new QVBoxLayout(this);


    generate = new QPushButton("generate points", this);
    connect(generate, SIGNAL(clicked()), this, SLOT(onGenerateClicked()));

    pointsCountSpin = new QSpinBox(this);
    pointsCountSpin->setMaximum(5000);
    pointsCountSpin->setValue(100);
    pointsCountSpin->setSuffix(" points");


    rectangleX = new QSpinBox(this);
    rectangleX->setMaximum(god->getCanvas()->width());
    rectangleX->setSuffix(" x");
    rectangleX->setValue(100);
    connect(rectangleX, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int i){onRectangleChanged();});

    rectangleY = new QSpinBox(this);
    rectangleY->setMaximum(god->getCanvas()->height());
    rectangleY->setSuffix(" y");
    rectangleY->setValue(100);
    connect(rectangleY, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int i){onRectangleChanged();});

    rectangleH = new QSpinBox(this);
    rectangleH->setMaximum(god->getCanvas()->width());
    rectangleH->setSuffix(" height");
    rectangleH->setValue(100);
    connect(rectangleH, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int i){onRectangleChanged();});

    rectangleW = new QSpinBox(this);
    rectangleW->setMaximum(god->getCanvas()->width());
    rectangleW->setSuffix(" width");
    rectangleW->setValue(100);
    connect(rectangleW, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int i){onRectangleChanged();});

    QRect rect = QRect(rectangleX->value(), rectangleY->value(),
                       rectangleW->value(), rectangleH->value());
    god->getCanvas()->setRect(rect);

    pointsInRectVal = new QLabel();
    pointsInRectVal->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    pointsInRectSuffix = new QLabel("points in rect");
    pointsInRectSuffix->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    lines = new QPushButton("show|hide lines", this);
    connect(lines, SIGNAL(clicked()), this, SLOT(onShowOrHideLinesClicked()));



    bottomLayout = new QHBoxLayout(this);
    bottomLayout->addWidget(generate);
    bottomLayout->addWidget(pointsCountSpin);
    bottomLayout->addWidget(rectangleX);
    bottomLayout->addWidget(rectangleY);
    bottomLayout->addWidget(rectangleH);
    bottomLayout->addWidget(rectangleW);
    bottomLayout->addWidget(pointsInRectVal);
    bottomLayout->addWidget(pointsInRectSuffix);
    bottomLayout->addWidget(lines);




    mainLayout->addWidget(god->getCanvas());
    mainLayout->addLayout(bottomLayout);

    onRectangleChanged();
    setLayout(mainLayout);
}

void MainWindow::onGenerateClicked() {
    god->generate(pointsCountSpin->value());
    onRectangleChanged();
}

void MainWindow::onShowOrHideLinesClicked() {
    god->getCanvas()->showOrHideLines();
}

void MainWindow::onRectangleChanged() {
    QRect rect = QRect(rectangleX->value(), rectangleY->value(),
                       rectangleW->value(), rectangleH->value());
    god->getCanvas()->setRect(rect);
    pointsInRectVal->setText(QString().setNum(god->findPointsInRectangle(rect)));
    god->getCanvas()->repaint();
}
