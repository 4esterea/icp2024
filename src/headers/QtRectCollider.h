/**
 * @file QtRectCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Qt Rectangle Collider.
 */

#ifndef __QTRECTCOLLIDER_H__
#define __QTRECTCOLLIDER_H__

#include <cmath>
#include "../interfaces/IQtRectCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

/**
 * @brief The QtRectCollider class Collider based on rectangle qt graphics
 */
class QtRectCollider : public IQtRectCollider {
public:
    /**
     * @brief QtRectCollider Constructor of qt rectangle collider
     * @param x X coordinate
     * @param y Y coordinate
     * @param angle Angle of rotation
     * @param width Width
     * @param height Height
     */
    QtRectCollider(double x, double y, double angle, double width, double height);
    /**
     * @brief GetPosition Returns position of the object
     * @return Position
     */
    IPosition * GetPosition();
    /**
     * @brief SetCoords Sets x and y coords of an objects
     * @param x X coord
     * @param y Y coord
     */
    void SetCoords(double x, double y);
    /**
     * @brief GetWidth Returns width of the object
     * @return Width
     */
    double GetWidth();
    /**
     * @brief SetWidth Sets width of the object
     * @param width New width
     */
    void SetWidth(double width);
    /**
     * @brief GetHeight Returns height of the object
     * @return Height
     */
    double GetHeight();
    /**
     * @brief SetHeight Sets new height of the object
     * @param height New height
     */
    void SetHeight(double height);
    /**
     * @brief GetAngle Returns rotation angle of the object
     * @return Rotation angle
     */
    double GetAngle();
    /**
     * @brief SetAngle Sets rotation angle of the object
     * @param angle New rotation angle
     */
    void SetAngle(double angle);
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    bool CheckCollision(ICollider * collider);
};

#endif
