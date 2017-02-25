//
// Created by ihb on 21.02.17.
//

#ifndef INC_2DTREE_STATISTIC_H
#define INC_2DTREE_STATISTIC_H


#include "qdebug.h"
#include "workDir/algorithm/Tree2D.h"

class Statistic {

    static const int MAP_SIZE = 2000;

    int pointsArr[MAP_SIZE][MAP_SIZE];

    QVector<int> pointsCount;
    QVector<int> rectsSize;

    Tree2D* tree = new Tree2D();
    QVector<QPoint> points;



public:
    void run();
    void runBalanced();
};


#endif //INC_2DTREE_STATISTIC_H
