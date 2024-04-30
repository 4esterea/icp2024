#ifndef HOVERABLEOBSTACLE_H
#define HOVERABLEOBSTACLE_H

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsRectItem>
#include <QBrush>

class HoverableObstacle : public QGraphicsRectItem {

public:
    HoverableObstacle(QGraphicsItem *parent = nullptr);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    QWidget* widgetToDisplay;
};

#endif // HOVERABLEOBSTACLE_H
