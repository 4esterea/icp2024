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

class ICollider {
    public:
    /**
     * @brief Gets the position of the collider.
     *
     * @return A pointer to the position of the collider.
     */
    IPosition * GetPosition();

    /**
     * @brief Gets the type of the collider.
     *
     * @return The type of the collider.
     */
    ColliderType GetColliderType();

    /**
     * @brief Checks if this collider is colliding with another collider.
     *
     * @param collider The other collider to check collision with.
     * @return True if this collider is colliding with the other collider, false otherwise.
     */
    virtual bool CheckCollision(ICollider * collider) = 0;

    /**
     * @brief Virtual destructor for the ICollider interface.
     */
    virtual ~ICollider();

    protected:
        IPosition * _position;
        ColliderType _colliderType;
};

#endif
