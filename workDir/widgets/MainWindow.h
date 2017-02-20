//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_MAINWIDGET_H
#define INC_2DTREE_MAINWIDGET_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include "../God.h"

class MainWindow : public QWidget{

    Q_OBJECT

public:
    MainWindow(QWidget* parent=0);


private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* bottomLayout;

    QPushButton* generate;

    God* god;

private slots:
    void onGenerateClicked();

};


#endif //INC_2DTREE_MAINWIDGET_H
