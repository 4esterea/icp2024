/**
* @file ObstacleGraphicItem.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Declaration of ObstacleGraphicItem
 */



#ifndef OBSTACLEGRAPHICITEM_H
#define OBSTACLEGRAPHICITEM_H

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsRectItem>
#include <QBrush>
#include "ObstacleWidget.h"
#include "src/headers/Obstacle.h"
#include "Viewport.h"
#include <QGraphicsRectItem>
#include <QPen>
#include <QDebug>
#include <QWidget>
#include <QPointF>
#include "../mainwindow.h"

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
    QWidget* _viewport;
    ObstacleWidget* _settings = nullptr;
    Obstacle* _obstacle;
public slots:
    void setRotation(int angle);
    void setWidth(int width);
    void setHeight(int height);
};

#endif // OBSTACLEGRAPHICITEM_H
