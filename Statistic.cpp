//
// Created by ihb on 21.02.17.
//

#include "Statistic.h"
#include "workDir/utils/Utils.h"

void Statistic::run() {


    pointsCount << 100 << 1000 << 10000 << 100000;

    /*for(int i=10; i<=1000; i+=100){
        rectsSize << i;
    }*/

    double compare = 0;

    rectsSize << 50 << 100 << 500 << 1000;

    QPoint point;
    StatisticResult* result = new StatisticResult();
    int countIteration;

    for(int pointCount : pointsCount){
        for(int rectSize : rectsSize){
            points.clear();
            points.reserve(pointCount);
            tree->clear();

            result->countOfCompare = 0;
            result->pointsInRect = 0;
            countIteration = 0;

            while(points.size()<pointCount){
                do {
                    point = Utils::generatePoint(0, 0, MAP_SIZE, MAP_SIZE);
                } while (points.contains(point));

                tree->addPoint(point);
                points.push_back(point);
            }

            for(int fromX=0; fromX<MAP_SIZE-rectSize; fromX+=100){
                for(int fromY=0; fromY<MAP_SIZE-rectSize; fromY+=100){
                    countIteration++;
                    tree->findPointsInRectangleStatistic(QRect(fromX, fromY, rectSize, rectSize), result);
                }
            }


            qDebug() << "pointsCount = " + QString::number(pointCount) +  " rectSize = " + QString::number(rectSize)
                     + " compare = " + QString::number((double)result->countOfCompare/countIteration)
                     + " inRect = " + QString::number((double)result->pointsInRect/countIteration)
                     + " iteration = " + QString::number(countIteration);

            compare += (double)result->countOfCompare/countIteration;
        }
    }

    qDebug() << "middle = " + QString::number(compare/rectsSize.size());
    qDebug() << "tree height = " + QString::number(tree->height());


}
