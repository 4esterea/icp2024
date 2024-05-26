/**
 * @file ICollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Collider interface
 */

#ifndef __ICOLLIDER_H__
#define __ICOLLIDER_H__

#include <QGraphicsItem>
#include "IPosition.h"
#include "../headers/types.h"

using namespace std;

/**
 * @brief The ICollider class Base for colliders
 */
class ICollider {
public:
    /**
     * @brief GetPosition Returns position of the collider
     * @return Position
     */
    IPosition * GetPosition() { return this->_position; };
    /**
     * @brief GetColliderType Returns collider's type
     * @return Type of collider
     */
    ColliderType GetColliderType() { return this->_colliderType; };
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    virtual bool CheckCollision(ICollider * collider) = 0;
    /**
     * @brief ~IGameObject Virtual desctructor
     */
    virtual ~ICollider() {};

protected:
    IPosition * _position;
    ColliderType _colliderType;
};

#endif
