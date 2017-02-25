//
// Created by ihb on 20.02.17.
//

#include "Tree2D.h"
#include "../utils/Utils.h"

QLine Tree2D::addPoint(QPoint point) {

    int fromX = 0, fromY = 0, toX = 2000, toY = 2000;

    if (root == nullptr) {
        root = new Node(nullptr, point, X);
        return QLine(point.x(), fromY, point.x(), toY);
    }

    Node *curr = root;

    while (true) {
        if (curr->axis == X) {
            if (point.x() < curr->point.x()) {
                if (curr->left != nullptr) {
                    toX = curr->point.x();
                    curr = curr->left;
                } else {
                    toX = curr->point.x();
                    Node *node = new Node(curr, point, Y);
                    curr->left = node;
                    return QLine(fromX, node->point.y(), toX, node->point.y());
                }
            } else {
                if (curr->right != nullptr) {
                    fromX = curr->point.x();
                    curr = curr->right;
                } else {
                    fromX = curr->point.x();
                    Node *node = new Node(curr, point, Y);
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
                    Node *node = new Node(curr, point, X);
                    curr->left = node;
                    return QLine(node->point.x(), fromY, node->point.x(), toY);
                }
            } else {
                if (curr->right != nullptr) {
                    fromY = curr->point.y();
                    curr = curr->right;
                } else {
                    fromY = curr->point.y();
                    Node *node = new Node(curr, point, X);
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

    if (node->axis == X) {
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

Node::Node(Node *parent, QPoint point, Axis dir) {
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
    this->point = point;
    this->axis = dir;
}

Node::Node(QPoint point, Node* left, Node* right, Axis dir) {
    this->left = left;
    this->right = right;
    this->point = point;
    this->axis = dir;
}




void Tree2D::findPointsInRectangleStatistic(QRect rect, StatisticResult* res) {
    findPointsInRectangleStatistic(rect, root, res);
    return;
}

void Tree2D::findPointsInRectangleStatistic(QRect &rect, Node *node, StatisticResult* res) {

    if (node == nullptr)
        return;

    res->countOfCompare++;
    if (rect.contains(node->point)) {
        res->pointsInRect++;
        findPointsInRectangleStatistic(rect, node->right, res);
        findPointsInRectangleStatistic(rect, node->left, res);
        return;
    }

    if (node->axis == X) {
        //res->countOfCompare++;
        if (Utils::isRectangleRightOfPoint(node->point, rect)) {
            findPointsInRectangleStatistic(rect, node->right, res);
        }
        if (Utils::isRectangleLeftOfPoint(node->point, rect)) {
            findPointsInRectangleStatistic(rect, node->left, res);
        }
    } else {
        //res->countOfCompare++;
        if (Utils::isRectangleAboveOfPoint(node->point, rect)) {
            findPointsInRectangleStatistic(rect, node->left, res);
        }
        if (Utils::isRectangleBelowOfPoint(node->point, rect)) {
            findPointsInRectangleStatistic(rect, node->right, res);
        }
    }

    return;
}

int Tree2D::height() {
    return height(root);
}

int max(int a,int b){
    return a > b ? a : b;
}

int Tree2D::height(Node *node) {
    if (node == nullptr)
        return 0;
    else
        return max(height(node->left), height(node->right)) + 1;
}

void Tree2D::fillTree(QVector<QPoint> points) {
    root = fillTree(points, X);
}

Node* Tree2D::fillTree(QVector<QPoint> points, Axis dir) {

    if(points.size()==0)
        return nullptr;

    if (dir == X)
        qSort(points.begin(), points.end(), [](const QPoint &a, const QPoint &b) -> bool {
            return a.x() < b.x();
        });
    else
        qSort(points.begin(), points.end(), [](const QPoint &a, const QPoint &b) -> bool {
            return a.y() < b.y();
        });

    int middle = points.size()/2;
    QVector<QPoint> left = points.mid(0, middle);
    QVector<QPoint> right = points.mid(middle+1);

    if(dir == X){
        return new Node(points.at(middle), fillTree(left, Y), fillTree(right, Y), X);
    } else {
        return new Node(points.at(middle), fillTree(left, X), fillTree(right, X), Y);
    }
}
