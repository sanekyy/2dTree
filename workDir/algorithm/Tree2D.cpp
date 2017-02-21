//
// Created by ihb on 20.02.17.
//

#include "Tree2D.h"
#include "../utils/Utils.h"

QLine Tree2D::addPoint(QPoint point) {

    int fromX = 0, fromY = 0, toX = 2000, toY = 2000;

    if (root == nullptr) {
        root = new Node(nullptr, point, VERTICAL);
        return QLine(point.x(), fromY, point.x(), toY);
    }

    Node *curr = root;

    while (true) {
        if (curr->dir == VERTICAL) {
            if (point.x() < curr->point.x()) {
                if (curr->left != nullptr) {
                    toX = curr->point.x();
                    curr = curr->left;
                } else {
                    toX = curr->point.x();
                    Node *node = new Node(curr, point, HORIZONTAL);
                    curr->left = node;
                    return QLine(fromX, node->point.y(), toX, node->point.y());
                }
            } else {
                if (curr->right != nullptr) {
                    fromX = curr->point.x();
                    curr = curr->right;
                } else {
                    fromX = curr->point.x();
                    Node *node = new Node(curr, point, HORIZONTAL);
                    curr->right = node;
                    return QLine(fromX, node->point.y(), toX, node->point.y());
                }
            }
        } else {
            if (point.y() < curr->point.y()) {
                if (curr->left != nullptr) {
                    toY = curr->point.y();
                    curr = curr->left;
                } else {
                    toY = curr->point.y();
                    Node *node = new Node(curr, point, VERTICAL);
                    curr->left = node;
                    return QLine(node->point.x(), fromY, node->point.x(), toY);
                }
            } else {
                if (curr->right != nullptr) {
                    fromY = curr->point.y();
                    curr = curr->right;
                } else {
                    fromY = curr->point.y();
                    Node *node = new Node(curr, point, VERTICAL);
                    curr->right = node;
                    return QLine(node->point.x(), fromY, node->point.x(), toY);
                }
            }
        }
    }

}

QVector<QPoint> Tree2D::findPointsInRectangle(QRect &rect) {
    return findPointsInRectangle(rect, root);
}

QVector<QPoint> Tree2D::findPointsInRectangle(QRect &rect, Node *node) {
    QVector<QPoint> res;

    if (node == nullptr)
        return res;

    if (rect.contains(node->point)) {
        res << node->point;

    }

    if (node->dir == VERTICAL) {
        if (Utils::isRectangleRightOfPoint(node->point, rect)) {
            res << findPointsInRectangle(rect, node->right);
        }
        if (Utils::isRectangleLeftOfPoint(node->point, rect)) {
            res << findPointsInRectangle(rect, node->left);
        }
    } else {
        if (Utils::isRectangleAboveOfPoint(node->point, rect)) {
            res << findPointsInRectangle(rect, node->left);
        }
        if (Utils::isRectangleBelowOfPoint(node->point, rect)) {
            res << findPointsInRectangle(rect, node->right);
        }
    }

    return res;
}

void Tree2D::clear() {
    root = nullptr;
}

Node::Node(Node *parent, QPoint point, Direction dir) {
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
    this->point = point;
    this->dir = dir;
}
