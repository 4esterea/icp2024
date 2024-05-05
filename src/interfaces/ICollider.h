/**
 * @file ICollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Collider doubleerface
 */

#ifndef __ICOLLIDER_H__
#define __ICOLLIDER_H__

#include <QGraphicsItem>
#include "IPosition.h"
#include "../headers/types.h"

using namespace std;

class ICollider {
    public:
        IPosition * GetPosition() { return this->_position; };
        ColliderType GetColliderType() { return this->_colliderType; };
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~ICollider() {};

    protected:
        IPosition * _position;
        ColliderType _colliderType;
};

#endif
