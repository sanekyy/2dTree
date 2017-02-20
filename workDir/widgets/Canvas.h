//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_CANVAS_H
#define INC_2DTREE_CANVAS_H

#include <QtWidgets/QWidget>
#include "QPaintEvent"

class Canvas : public QWidget{

    Q_OBJECT

public:
    Canvas(QWidget* parent = 0);
    void paintEvent(QPaintEvent*);
};


#endif //INC_2DTREE_CANVAS_H
