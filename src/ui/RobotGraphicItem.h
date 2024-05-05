/**
* @file RobotGraphicItem.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Declaration of RobotGraphicItem
 */


#ifndef ROBOTGRAPHICITEM_H
#define ROBOTGRAPHICITEM_H

#include "Viewport.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsObject>
#include <QPen>
#include <QDebug>
#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QPointF>
#include "RobotWidget.h"
#include "../mainwindow.h"

class AutoRobot;

class RobotGraphicItem : public QGraphicsEllipseItem
{
public:
    /**
     * @brief Constructor for RobotGraphicItem class.
     *
     * @param viewport The viewport object.
     * @param parent The parent QGraphicsItem object.
     * @param robot The IRobot object.
     */
    RobotGraphicItem(Viewport* viewport = nullptr, QGraphicsItem *parent = nullptr, IRobot * robot = nullptr);

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
    * @brief Overridden keyPressEvent function to handle key press events.
    *
    * This function is called when a key is pressed. If the robot is remote-controlled (_isRemote is true),
    * it handles the W, A, S, D keys to control the robot's movements. If the robot is not remote-controlled,
    * it does not handle the key presses.
    *
    * @param event The QKeyEvent object representing the key press event.
    */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief Updates the RobotGraphicItem.
     */
    void Update();

    /**
     * @brief Gets the settings of the RobotGraphicItem.
     *
     * @return A pointer to the QWidget object.
     */
    QWidget* getSettings();

    /**
     * @brief Gets the IRobot object.
     *
     * @return A pointer to the IRobot object.
     */
    IRobot* getGameObject();

    /**
     * @brief Gets the vision of the RobotGraphicItem.
     *
     * @return A pointer to the QGraphicsRectItem object.
     */
    QGraphicsRectItem* getVision();

private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QWidget* _viewport;
    QWidget* _settings = nullptr;
    IRobot* _robot;
    QGraphicsRectItem* _vision = nullptr;
    bool _isRemote = false;
    QGraphicsLineItem* _direction = nullptr;

public slots:
    void setRotation(int angle);
};

#endif // ROBOTGRAPHICITEM_H
