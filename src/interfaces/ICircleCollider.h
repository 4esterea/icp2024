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

/**
 * @brief The ICircleCollider class Basic circle collider
 */
class ICircleCollider : public ICollider {
public:
    /**
     * @brief GetRadius Returns radius of the collider
     * @return Ragius
     */
    virtual double GetRadius() = 0;
    /**
     * @brief SetRadius Assignes new radius to the collider
     * @param radius New radius
     */
    virtual void SetRadius(double radius) = 0;
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    virtual bool CheckCollision(ICollider * collider) = 0;
    /**
     * @brief ~IGameObject Virtual desctructor
     */
    virtual ~ICircleCollider() {};

protected:
    double _radius;
};

#endif
