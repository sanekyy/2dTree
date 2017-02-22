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

    double allCompare = 0;
    double compare = 0;

    rectsSize << 25 << 50 << 100 << 200;

    QPoint point = QPoint(1000, 1000);
    StatisticResult *result = new StatisticResult();
    int countIteration;

    for (int pointCount : pointsCount) {
        for (int rectSize : rectsSize) {

            result->countOfCompare = 0;
            result->pointsInRect = 0;
            countIteration = 0;
            compare = 0;

            while (points.size() < pointCount) {
                while (points.contains(point)) {
                    point = Utils::generatePoint(0, 0, MAP_SIZE, MAP_SIZE);
                }

                tree->addPoint(point);
                points.push_back(point);
            }

            for (int fromX = 0; fromX < MAP_SIZE / 2; fromX += 100) {
                for (int fromY = 0; fromY < MAP_SIZE / 2; fromY += 100) {
                    countIteration++;
                    tree->findPointsInRectangleStatistic(QRect(fromX, fromY, rectSize, rectSize), result);
                }
            }


            qDebug() << "pointsCount = " + QString::number(pointCount) + " rectSize = " + QString::number(rectSize)
                        + " allCompare = " + QString::number((double) result->countOfCompare / countIteration)
                        + " inRect = " + QString::number((double) result->pointsInRect / countIteration)
                        + " iteration = " + QString::number(countIteration)
                        + " tree height = " + QString::number(tree->height());

            allCompare += (double) result->countOfCompare / countIteration;
        }
    }

    qDebug() << "middle = " + QString::number(allCompare / rectsSize.size() / pointsCount.size());
    qDebug() << "tree height = " + QString::number(tree->height());
}

void Statistic::runBalanced() {


    pointsCount << 50000 << 55000 << 60000;

    /*for(int i=10; i<=1000; i+=100){
        rectsSize << i;
    }*/

    double allCompare = 0;
    double compare = 0;

    rectsSize << 100 << 125 << 150<< 175;

    QPoint point = QPoint(1000,1000);
    StatisticResult* result = new StatisticResult();
    int countIteration;

    for(int pointCount : pointsCount){
        for(int rectSize : rectsSize){

            result->countOfCompare = 0;
            result->pointsInRect = 0;
            countIteration = 0;
            compare = 0;

            while(points.size()<pointCount){
                while (points.contains(point)) {
                    point = Utils::generatePoint(0, 0, MAP_SIZE, MAP_SIZE);
                }
                points.push_back(point);
            }

            tree->clear();
            tree->fillTree(points);

            for(int fromX=0; fromX<MAP_SIZE/2; fromX+=100){
                for(int fromY=0; fromY<MAP_SIZE/2; fromY+=100){
                    countIteration++;
                    tree->findPointsInRectangleStatistic(QRect(fromX, fromY, rectSize, rectSize), result);
                }
            }


            qDebug() << "pointsCount = " + QString::number(pointCount) +  " rectSize = " + QString::number(rectSize)
                        + " allCompare = " + QString::number((double)result->countOfCompare/countIteration)
                        + " inRect = " + QString::number((double)result->pointsInRect/countIteration)
                        + " iteration = " + QString::number(countIteration)
                        + " tree height = " + QString::number(tree->height());

            allCompare += (double)result->countOfCompare/countIteration;
        }
    }

    qDebug() << "middle = " + QString::number(allCompare/rectsSize.size()/pointsCount.size());
    qDebug() << "tree height = " + QString::number(tree->height());
}


