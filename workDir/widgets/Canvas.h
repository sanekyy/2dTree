//
// Created by ihb on 20.02.17.
//

#ifndef INC_2DTREE_CANVAS_H
#define INC_2DTREE_CANVAS_H

#include <QtWidgets/QWidget>
#include "QPaintEvent"
#include "QVector"
#include "QLine"
#include "QPoint"

class Canvas : public QWidget{
    Q_OBJECT

    bool canDraw = false;

    QRect rectangle;
    QVector<QPoint> pointsInRect;

    QVector<QLine> lines;
    QVector<QPoint> points;

    bool canDrawLines = false;

public:
    Canvas(QWidget* parent = 0);
    void enableDraw(){ canDraw = true; }

    void clear();

    void paintEvent(QPaintEvent*);

    void setRect(QRect rect);

    void setPointsInRest(QVector<QPoint> vector);

    void setLines(QVector<QLine> vector);

    void setPoints(QVector<QPoint> vector);

    void showOrHideLines();
};


#endif //INC_2DTREE_CANVAS_H
