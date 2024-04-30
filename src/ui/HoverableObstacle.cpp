#include "HoverableObstacle.h"
#include <QGraphicsRectItem>
#include <QPen>
#include <QDebug>

HoverableObstacle::HoverableObstacle(QGraphicsItem* parent) : QGraphicsRectItem(parent) {
    setAcceptHoverEvents(true);
}


void HoverableObstacle::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {

    setPen(QPen({Qt::red, 2}));
    QGraphicsRectItem::hoverEnterEvent(event);
}

void HoverableObstacle::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {

    setPen(QPen({Qt::white, 2}));
    QGraphicsRectItem::hoverLeaveEvent(event);
}

void HoverableObstacle::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QPointF position = this->pos();
    qreal x = position.x();
    qreal y = position.y();
    qDebug() << "Obstacle was clicked on! The current position is: " << x << " : " << y;
    QGraphicsRectItem::mousePressEvent(event);
}

