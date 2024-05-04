#ifndef ROBOTGRAPHICITEM_H
#define ROBOTGRAPHICITEM_H

#include "Viewport.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsObject>
#include <QPen>
#include <QDebug>
#include <QWidget>
#include <QGraphicsSceneHoverEvent>
#include <QPointF>
#include "RobotWidget.h"
#include "../mainwindow.h"

class AutoRobot;

class RobotGraphicItem : public QGraphicsEllipseItem
{
public:
    RobotGraphicItem(Viewport* viewport = nullptr, QGraphicsItem *parent = nullptr, IRobot * robot = nullptr);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
    QWidget* getSettings();

private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QWidget* _viewport;
    QWidget* _settings = nullptr;
    IRobot * _robot;
    QGraphicsRectItem* _vision = nullptr;
    bool _isRemote = false;
    QGraphicsLineItem* _direction = nullptr;

public slots:
    void setRotation(int angle);
};

#endif // ROBOTGRAPHICITEM_H
