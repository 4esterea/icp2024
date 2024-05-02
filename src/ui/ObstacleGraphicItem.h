#ifndef OBSTACLEGRAPHICITEM_H
#define OBSTACLEGRAPHICITEM_H

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsRectItem>
#include <QBrush>
#include "ObstacleWidget.h"
#include "src/headers/Obstacle.h"
#include "Viewport.h"

class ObstacleWidget;

class ObstacleGraphicItem : public QGraphicsRectItem {

public:
    ObstacleGraphicItem(Viewport* viewport = nullptr, QGraphicsItem *parent = nullptr, Obstacle* obstacle = nullptr);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
    ObstacleWidget* getSettings();
private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QWidget* viewport;
    ObstacleWidget* settings = nullptr;
    Obstacle* obstacle;
public slots:
    void setRotation(int angle);
    void setWidth(int width);
    void setHeight(int height);
};

#endif // OBSTACLEGRAPHICITEM_H
