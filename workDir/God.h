//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_GOD_H
#define INC_2DTREE_GOD_H


#include <QtCore/QPoint>
#include <QtCore/QVector>
#include "widgets/Canvas.h"
#include "algorithm/Tree2D.h"

class God {

    Canvas* canvas;
    Tree2D tree;

    QVector<QPoint> points;

public:
    God(Canvas* canvas);

    void generate(int count);
    void findPointsInRectangle(QRect rect);
    Canvas* getCanvas() const;
};


#endif //INC_2DTREE_GOD_H
