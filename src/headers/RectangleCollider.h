/**
 * @file RectangleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Rectangle Collider.
 */

#ifndef __RECTANGLECOLLIDER_H__
#define __RECTANGLECOLLIDER_H__

#include "../interfaces/IRectangleCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

/**
 * @brief The RectangleCollider class Basic rectangle collider
 */
class RectangleCollider : public IRectangleCollider {
public:
    /**
     * @brief RectangleCollider Constructor of basic rectangle collider
     * @param x X coordinate
     * @param y Y coordinate
     * @param angle Angle of rotation
     * @param width Width
     * @param height Height
     */
    RectangleCollider(double x, double y, double angle, double width, double height);
    /**
     * @brief Get the width of the collider.
     * @return The width of the collider.
     */
    virtual double GetWidth() = 0;
    /**
     * @brief Set the width of the collider.
     * @param width The new width for the collider.
     */
    virtual void SetWidth(double width) = 0;
    /**
     * @brief Get the height of the collider.
     * @return The height of the collider.
     */
    virtual double GetHeight() = 0;
    /**
     * @brief Set the height of the collider.
     * @param height The new height for the collider.
     */
    void SetHeight(double height);
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    bool CheckCollision(ICollider * collider);
};

#endif
