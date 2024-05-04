/**
 * @file IGameObject.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Game Object doubleerface
 */

#ifndef __IGAMEOBJECT_H__
#define __IGAMEOBJECT_H__

#include "IPosition.h"
#include "ICollider.h"
#include "../headers/types.h"

using namespace std;

class IMap;

class IGameObject {
public:
    ICollider * GetCollider() { return this->_collider; };
    IPosition * GetPosition() { return this->_position; };
    ObjectType GetObjectType() { return this->_objectType; };
    void SetMap(IMap * map) { this->_map = map; }
    double GetId() { return this->_id; }
    void SetId(double id) { this->_id = id; }
    virtual void Update() = 0;
    virtual ~IGameObject() {};

protected:
    IPosition * _position;
    ICollider * _collider;
    ObjectType _objectType;
    IMap * _map; // Map to which GameObject belongs
    double _id; // Id of object whithin the map
};

#endif
