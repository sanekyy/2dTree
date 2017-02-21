//
// Created by ihb on 20.02.17.
//

#include <QtCore/QTime>
#include <QtCore/QRect>
#include "Utils.h"

QPoint Utils::generatePoint(int fromX, int fromY, int toX, int toY) {
    return QPoint(rand() % (toX - fromX) + fromX, rand() % (toY - fromY) + fromY);
}

bool Utils::isPointInRectangle(QPoint &point, QRect &rect) {
    return rect.top() < point.y() && rect.bottom() > point.y() &&
           rect.left() < point.x() && rect.right() > point.x();
}

bool Utils::isRectangleRightOfPoint(QPoint &point, QRect &rect) {
    return rect.right() > point.x();
}

bool Utils::isRectangleLeftOfPoint(QPoint &point, QRect &rect) {
    return rect.left() < point.x();
}

bool Utils::isRectangleAboveOfPoint(QPoint &point, QRect &rect) {
    return rect.top() < point.y();
}

bool Utils::isRectangleBelowOfPoint(QPoint &point, QRect &rect) {
    return rect.bottom() > point.y();
}
