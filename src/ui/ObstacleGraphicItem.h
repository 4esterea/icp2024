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
#include <QPen>
#include "ObstacleWidget.h"
#include "src/headers/Obstacle.h"
#include "Viewport.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include <QWidget>
#include <QPointF>
#include "../mainwindow.h"

class ObstacleWidget;

/**
 * @class ObstacleGraphicItem
 * @brief This class represents a custom QGraphicsRectItem for an obstacle in the application.
 *
 * The ObstacleGraphicItem class extends QGraphicsRectItem and provides functionalities for handling
 * different events and managing the graphical representation of an obstacle in the GUI.
 */
class ObstacleGraphicItem : public QGraphicsRectItem {

public:
    /**
     * @brief Constructor for ObstacleGraphicItem class.
     *
     * @param viewport The viewport object.
     * @param parent The parent QGraphicsItem object.
     * @param obstacle The obstacle object.
     */
    ObstacleGraphicItem(Viewport* viewport = nullptr, QGraphicsItem *parent = nullptr, Obstacle* obstacle = nullptr);

    /**
     * @brief Event handler for hover enter event.
     *
     * @param event The QGraphicsSceneHoverEvent object.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);

    /**
     * @brief Event handler for hover leave event.
     *
     * @param event The QGraphicsSceneHoverEvent object.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

    /**
     * @brief Event handler for mouse double click event.
     *
     * @param event The QGraphicsSceneMouseEvent object.
     */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

    /**
     * @brief Gets the settings of the ObstacleWidget.
     *
     * @return A pointer to the ObstacleWidget object.
     */
    ObstacleWidget* getSettings();

private:

    /**
     * @brief Handles changes to the item's properties.
     *
     * @param change The type of change that occurred.
     * @param value The new value of the property.
     * @return The possibly modified new value of the property.
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QWidget* _viewport;
    ObstacleWidget* _settings = nullptr;
    Obstacle* _obstacle;
public slots:
    /**
     * @brief Sets the rotation of the ObstacleGraphicItem.
     *
     * @param angle The angle to set the rotation to.
     */
    void setRotation(int angle);

    /**
     * @brief Sets the width of the ObstacleGraphicItem.
     *
     * @param width The width to set the ObstacleGraphicItem to.
     */
    void setWidth(int width);

    /**
     * @brief Sets the height of the ObstacleGraphicItem.
     *
     * @param height The height to set the ObstacleGraphicItem to.
     */
    void setHeight(int height);
};

#endif // OBSTACLEGRAPHICITEM_H
