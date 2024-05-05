/**
 * @file CircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Circle Collider.
 */

#ifndef __CIRCLECOLLIDER_H__
#define __CIRCLECOLLIDER_H__

#include <cmath>
#include "../interfaces/ICircleCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

class CircleCollider : public ICircleCollider {
    public:
    /**
    * @brief Constructor for the CircleCollider class.
    *
    * @param x The initial x-coordinate of the collider.
    * @param y The initial y-coordinate of the collider.
    * @param angle The initial angle of the collider.
    * @param radius The radius of the collider.
    */
    CircleCollider(double x, double y, double angle, double radius);

    /**
     * @brief Gets the radius of the collider.
     *
     * @return The radius of the collider.
     */
    double GetRadius();

    /**
     * @brief Sets the radius of the collider.
     *
     * @param radius The radius to set the collider to.
     */
    void SetRadius(double radius);

    /**
     * @brief Checks if this collider is colliding with another collider.
     *
     * @param collider The other collider to check collision with.
     * @return True if this collider is colliding with the other collider, false otherwise.
     */
    bool CheckCollision(ICollider * collider);
};

#endif
