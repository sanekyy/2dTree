//
// Created by ihb on 20.02.17.
//

#include <QtGui/QPainter>
#include "Canvas.h"


Canvas::Canvas(QWidget *parent) : QWidget(parent) {

}


void Canvas::paintEvent(QPaintEvent*){
    QPainter painter(this);


}