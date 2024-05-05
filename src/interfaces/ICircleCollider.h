/**
 * @file ICircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Circle Collider interface
 */

#ifndef __ICIRCLECOLLIDER_H__
#define __ICIRCLECOLLIDER_H__

#include "ICollider.h"

using namespace std;

class ICircleCollider : public ICollider {
    public:
    /**
     * @brief Checks if this collider is colliding with another collider.
     *
     * @param collider The other collider to check collision with.
     * @return True if this collider is colliding with the other collider, false otherwise.
     */
    virtual bool CheckCollision(ICollider * collider) = 0;

    /**
     * @brief Gets the radius of the circle collider.
     *
     * @return The radius of the circle collider.
     */
    virtual double GetRadius() = 0;

    /**
     * @brief Sets the radius of the circle collider.
     *
     * @param radius The radius to set the circle collider to.
     */
    virtual void SetRadius(double radius) = 0;

    /**
     * @brief Virtual destructor for the ICircleCollider interface.
     */
    virtual ~ICircleCollider() {};

    protected:
        double _radius;
};

#endif
