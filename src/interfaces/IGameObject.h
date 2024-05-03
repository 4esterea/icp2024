/**
 * @file IGameObject.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Game Object interface
 */

#ifndef __IGAMEOBJECT_H__
#define __IGAMEOBJECT_H__

#include "IPosition.h"
#include "ICollider.h"
#include "../headers/types.h"

using namespace std;

class IGameObject {
public:
    ICollider * GetCollider() { return this->_collider; };
    IPosition * GetPosition() { return this->_position; };
    ObjectType GetObjectType() { return this->_objectType; };
    virtual void Update() = 0;
    virtual ~IGameObject() {};

protected:
    IPosition * _position;
    ICollider * _collider;
    ObjectType _objectType;
};

#endif
