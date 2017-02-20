//
// Created by ihb on 20.02.17.
//

#include "Tree2D.h"

void Tree2D::addPoint(QPoint point) {

    if(root == nullptr){
        root = new Node(nullptr, point, VERTICAL);
        return;
    }

    Node* curr = root;

    while(true){
        if(curr->dir == VERTICAL){
            if(point.x() < curr->point.x()){
                if(curr->left != nullptr)
                    curr = curr->left;
                else{
                    Node* node = new Node(curr, point, HORIZONTAL);
                    curr->left = node;
                    return;
                }
            } else {
                if(curr->right != nullptr)
                    curr = curr->right;
                else {
                    Node* node = new Node(curr, point, HORIZONTAL);
                    curr->right = node;
                    return;
                }
            }
        } else {
            if(point.y() < curr->point.y()){
                if(curr->left != nullptr)
                    curr = curr->left;
                else{
                    Node* node = new Node(curr, point, VERTICAL);
                    curr->left = node;
                    return;
                }
            } else {
                if(curr->right != nullptr)
                    curr = curr->right;
                else {
                    Node* node = new Node(curr, point, VERTICAL);
                    curr->right = node;
                    return;
                }
            }
        }
    }

}

QVector<int> Tree2D::findPointsInRectangle(QRect& rect, Node* node) {
    if(node == nullptr)
        return QVector();

    if()
}



Node::Node(Node *parent, QPoint point, Direction dir) {
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
    this->point = point;
    this->dir = dir;
}
