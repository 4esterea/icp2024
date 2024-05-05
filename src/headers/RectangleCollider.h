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

class RectangleCollider : public IRectangleCollider {
    public:
    /**
    * @brief Constructor for the RectangleCollider class.
    *
    * @param x The initial x-coordinate of the collider.
    * @param y The initial y-coordinate of the collider.
    * @param angle The initial angle of the collider.
    * @param width The width of the collider.
    * @param height The height of the collider.
    */
    RectangleCollider(double x, double y, double angle, double width, double height);

    /**
     * @brief Gets the width of the collider.
     *
     * @return The width of the collider.
     */
    double GetWidth();

    /**
     * @brief Sets the width of the collider.
     *
     * @param width The width to set the collider to.
     */
    void SetWidth(double width);

    /**
     * @brief Gets the height of the collider.
     *
     * @return The height of the collider.
     */
    double GetHeight();

    /**
     * @brief Sets the height of the collider.
     *
     * @param height The height to set the collider to.
     */
    void SetHeight(double height);

    /**
     * @brief Checks if this collider is colliding with another collider.
     *
     * @param collider The other collider to check collision with.
     * @return True if this collider is colliding with the other collider, false otherwise.
     */
    bool CheckCollision(ICollider * collider);
};

#endif
