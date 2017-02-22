//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_TREE2D_H
#define INC_2DTREE_TREE2D_H


#include <QtCore/QPoint>
#include <QtCore/QRect>
#include <QtCore/QVector>
#include <QtCore/QLine>


class StatisticResult{
public:
    int countOfCompare = 0;
    int pointsInRect = 0;
};


enum Axis {
    X,
    Y
};

class Node {

    Node *parent;
    Node *left;
    Node *right;

    QPoint point;
    Axis axis;

    friend class Tree2D;

public:
    Node(Node *parent, QPoint point, Axis direction);
    Node(QPoint point, Node* left, Node* right, Axis dir);
};


class Tree2D {
    Node *root = nullptr;


public:
    void clear();

    QLine addPoint(QPoint point);

    QVector<QPoint> findPointsInRectangle(QRect &rect);

    QVector<QPoint> findPointsInRectangle(QRect &rect, Node *node);

    void findPointsInRectangleStatistic(QRect rect, StatisticResult* res);

    void findPointsInRectangleStatistic(QRect &rect, Node *node, StatisticResult* res);

    int height();

    int height(Node* node);

    void fillTree(QVector<QPoint> points);

    Node *fillTree(QVector<QPoint> points, Axis dir);
};


#endif //INC_2DTREE_TREE2D_H
