#ifndef HOVERABLEOBSTACLE_H
#define HOVERABLEOBSTACLE_H

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsRectItem>
#include <QBrush>
#include "ObstacleWidget.h"

class ObstacleWidget;

class HoverableObstacle : public QGraphicsRectItem {

public:
    HoverableObstacle(QWidget* mainWindow, QGraphicsItem *parent = nullptr);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
    ObstacleWidget* getSettings();
private:
    QWidget* viewport;
    ObstacleWidget* settings = nullptr;
    bool isMoving;
public slots:
    void setRotation(int angle);
};

#endif // HOVERABLEOBSTACLE_H
