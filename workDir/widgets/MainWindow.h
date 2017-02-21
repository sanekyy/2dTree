//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_MAINWIDGET_H
#define INC_2DTREE_MAINWIDGET_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include "../God.h"

class MainWindow : public QWidget{

    Q_OBJECT

    QVBoxLayout* mainLayout;
    QHBoxLayout* bottomLayout;

    QPushButton* generate;
    QPushButton* lines;

    QSpinBox* pointsCountSpin;
    QSpinBox* rectangleX;
    QSpinBox* rectangleY;
    QSpinBox* rectangleH;
    QSpinBox* rectangleW;

    QLabel* pointsInRectVal;
    QLabel* pointsInRectSuffix;

    God* god;

public:
    MainWindow(QWidget* parent=0);

private slots:
    void onGenerateClicked();
    void onShowOrHideLinesClicked();
    void onRectangleChanged();
};


#endif //INC_2DTREE_MAINWIDGET_H
