//
// Created by ihb on 20.02.17.
//

#include <QtCore/QTime>
#include "God.h"
#include "utils/Utils.h"

God::God() {
    this->canvas = new Canvas();
    srand((uint) QTime::currentTime().msec());
}


void God::generate(int count) {

    canvas->clear();
    tree.clear();
    points.clear();
    points.reserve(count);
    lines.clear();
    lines.reserve(count);


    int fromX = 0;
    int fromY = 0;
    int toX = canvas->size().width();
    int toY = canvas->size().height();

    QPoint point;

    for(int i=0; i<count; i++){
        do {
            point = Utils::generatePoint(fromX, fromY, toX, toY);
        } while (points.contains(point));

        lines.push_back(tree.addPoint(point));
        points.push_back(point);

        canvas->setLines(lines);
        canvas->setPoints(points);
        canvas->repaint();
    }


    /*points << QPoint(9*10, 5*10) << QPoint(15*10, 4*10) << QPoint(5*10, 8*10) << QPoint(2*10, 1*10) << QPoint(1*10, 6*10);
    points << QPoint(7*10, 10*10) << QPoint(10*10, 3*10) << QPoint(19*10, 14*10) << QPoint(17*10, 11*10) << QPoint(13*10, 2*10);

    for (QPoint qPoint : points) {
        lines.push_back(tree.addPoint(qPoint));
        canvas->setLines(lines);
        canvas->setPoints(points);
        canvas->repaint();
    }*/
}

int God::findPointsInRectangle(QRect rect) {
    QVector<QPoint> res = tree.findPointsInRectangle(rect);
    qDebug() << res;
    canvas->setPointsInRest(res);
    return res.size();
}

Canvas* God::getCanvas() const {
    return canvas;
}
