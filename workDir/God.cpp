//
// Created by ihb on 20.02.17.
//

#include "God.h"
#include "utils/Utils.h"

God::God(Canvas *canvas) {
    this->canvas = canvas;
}


void God::generate(int count) {

    points.reserve(count);

    int fromX = 0;
    int fromY = 0;
    int toX = canvas->size().width();
    int toY = canvas->size().height();

    /*QPoint point;

    for(int i=0; i<count; i++){
        point = Utils::generatePoint(fromX, fromY, toX, toY);
        points.push_back(point);
        tree.addPoint(point);
    }*/

    points << QPoint(9,5) << QPoint(15,4) << QPoint(5,8) << QPoint(2,1) << QPoint(1,6);
    points << QPoint(7,10) << QPoint(10,3) << QPoint(19,14) << QPoint(17,11) << QPoint(13,2);

    for(QPoint qPoint : points){
        tree.addPoint(qPoint);
    }
}

void God::findPointsInRectangle(QRect rect) {
    tree.findPointsInRectangle(rect);
}

Canvas* God::getCanvas() const {
    return canvas;
}
