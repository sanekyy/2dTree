//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_TREE2D_H
#define INC_2DTREE_TREE2D_H


#include <QtCore/QPoint>
#include <QtCore/QRect>


enum Direction {
    VERTICAL,
    HORIZONTAL
};

class Node {

    Node* parent;
    Node* left;
    Node* right;

    QPoint point;
    Direction dir;

    friend class Tree2D;

public:
    Node(Node *parent, QPoint point, Direction direction);
};



class Tree2D {
    Node* root;


public:
    void addPoint(QPoint point);
    QVector<int> findPointsInRectangle(QRect& rect, Node *node = this->root);
};



#endif //INC_2DTREE_TREE2D_H
