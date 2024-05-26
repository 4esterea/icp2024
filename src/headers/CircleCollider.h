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
     * @brief CircleCollider Constructor of circle collider
     * @param x X coordinate
     * @param y Y coordinate
     * @param radius Radius of circle
     */
    CircleCollider(double x, double y, double angle, double radius);
    /**
     * @brief GetRadius Returns radius of the collider
     * @return Ragius
     */
    double GetRadius();
    /**
     * @brief SetRadius Assignes new radius to the collider
     * @param radius New radius
     */
    void SetRadius(double radius);
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    bool CheckCollision(ICollider * collider);
};

#endif
