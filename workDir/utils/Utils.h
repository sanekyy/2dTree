//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_UTILS_H
#define INC_2DTREE_UTILS_H


#include <QtCore/QPoint>

class Utils {

public:
    static QPoint generatePoint(int fromX, int fromY, int toX, int toY);

    static bool isPointInRectangle(QPoint& point, QRect& rect);

    static bool isRectangleRightOfPoint(QPoint& point, QRect &rect);

    static bool isRectangleLeftOfPoint(QPoint& point, QRect &rect);

    static bool isRectangleAboveOfPoint(QPoint &point, QRect &rect);

    static bool isRectangleBelowOfPoint(QPoint &point, QRect &rect);
};


#endif //INC_2DTREE_UTILS_H
