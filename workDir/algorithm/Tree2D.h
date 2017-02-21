//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_TREE2D_H
#define INC_2DTREE_TREE2D_H


#include <QtCore/QPoint>
#include <QtCore/QRect>
#include <QtCore/QVector>
#include <QtCore/QLine>


enum Direction {
    VERTICAL,
    HORIZONTAL
};

class Node {

    Node *parent;
    Node *left;
    Node *right;

    QPoint point;
    Direction dir;

    friend class Tree2D;

public:
    Node(Node *parent, QPoint point, Direction direction);
};


class Tree2D {
    Node *root = nullptr;


public:
    void clear();

    QLine addPoint(QPoint point);

    QVector<QPoint> findPointsInRectangle(QRect &rect);

    QVector<QPoint> findPointsInRectangle(QRect &rect, Node *node);
};


#endif //INC_2DTREE_TREE2D_H
