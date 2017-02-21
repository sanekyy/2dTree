//
// Created by ihb on 20.02.17.
//

#include <QtGui/QPainter>
#include "Canvas.h"


Canvas::Canvas(QWidget *parent) : QWidget(parent) {
}


void Canvas::paintEvent(QPaintEvent *) {


    QPainter painter(this);

    painter.setBrush(QBrush(Qt::black));
    painter.setPen(QPen(Qt::black));
    painter.drawRect(0, 0, this->width(), this->height());

    painter.setBrush(QBrush(Qt::darkCyan));
    painter.setPen(QPen(Qt::darkCyan));
    painter.drawRect(rectangle);

    painter.setBrush(QBrush(Qt::green));
    painter.setPen(QPen(Qt::green));
    if (canDrawLines)
        for (QLine line : lines) {
            painter.drawLine(line);
        }

    painter.setBrush(QBrush(Qt::white));
    painter.setPen(QPen(Qt::white));
    for (QPoint point : points) {
        painter.drawPoint(point);
    }


    painter.setBrush(QBrush(QColor(255,0,255)));
    painter.setPen(QPen(QColor(255,0,255)));
    for (QPoint point : pointsInRect) {
        painter.drawPoint(point);
    }
}

void Canvas::clear() {
    pointsInRect.clear();
    lines.clear();
    points.clear();

    QPainter painter(this);

    painter.setBrush(QBrush(Qt::white));
    painter.setPen(QPen(Qt::white));

    painter.drawRect(0, 0, this->width(), this->height());
}

void Canvas::setPointsInRest(QVector<QPoint> points) {
    pointsInRect = points;
}

void Canvas::setRect(QRect rect) {
    this->rectangle = rect;
}

void Canvas::setLines(QVector<QLine> lines) {
    this->lines = lines;
}

void Canvas::setPoints(QVector<QPoint> points) {
    this->points = points;
}

void Canvas::showOrHideLines() {
    canDrawLines = !canDrawLines;
    this->repaint();
}
