//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_GOD_H
#define INC_2DTREE_GOD_H



#include <QtCore/QPoint>
#include <QtCore/QVector>
#include "algorithm/Tree2D.h"
#include "widgets/Canvas.h"
#include "qdebug.h"

class God {

    Canvas *canvas;
    Tree2D tree;

    QVector<QPoint> points;
    QVector<QLine> lines;

public:
    God();

    void generate(int count);

    int findPointsInRectangle(QRect rect);

    Canvas *getCanvas() const;
};


#endif //INC_2DTREE_GOD_H
