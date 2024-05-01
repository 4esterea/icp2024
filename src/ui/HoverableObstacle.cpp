#include "HoverableObstacle.h"
#include <QGraphicsRectItem>
#include <QPen>
#include <QDebug>
#include "ObstacleWidget.h"

HoverableObstacle::HoverableObstacle(QWidget* viewport, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), viewport(viewport) {
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


void HoverableObstacle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
    QPointF position = this->pos();
    qreal x = position.x();
    qreal y = position.y();
    qDebug() << "Obstacle was clicked on! The current position is: " << x << " : " << y;
    if(settings == nullptr){
        settings = new ObstacleWidget(viewport, this);
    }

    // Get the dimensions of the viewport
    int viewportWidth = viewport->width();
    int viewportHeight = viewport->height();

    // Determine the nearest corner to the obstacle
    bool isCloserToLeft = x < viewportWidth / 2;
    bool isCloserToTop = y < viewportHeight / 2;

    // Calculate the new position for the ObstacleWidget
    qreal newX = isCloserToLeft ? x + settings->width()/2 : x - settings->width()/2;
    qreal newY = isCloserToTop ? y + settings->height()/2 : y - settings->height();

    // Set the position of the ObstacleWidget
    settings->move(newX, newY);
    settings->show();
    QGraphicsRectItem::mousePressEvent(event);
}

ObstacleWidget *HoverableObstacle::getSettings()
{
    return this->settings;
}

void HoverableObstacle::setRotation(int angle) {
    QGraphicsRectItem::setRotation(angle);
}

