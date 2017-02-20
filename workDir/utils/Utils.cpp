//
// Created by ihb on 20.02.17.
//

#include <QtCore/QTime>
#include <QtCore/QRect>
#include "Utils.h"

QPoint Utils::generatePoint(int fromX, int fromY, int toX, int toY) {
    qsrand((uint) QTime::currentTime().msec());
    return QPoint(rand() % (toX - fromX) + fromX, rand() % (toY - fromY) + fromY);
}

bool Utils::isPointInRectangle(QPoint point, QRect rect) {
    return rect.top()<point.y() && rect.bottom()>point
}
