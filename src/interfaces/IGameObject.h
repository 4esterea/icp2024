/**
 * @file IGameObject.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Game Object interface
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
    int GetId() { return this->_id; }
    void SetId(int id) { this->_id = id; }
    virtual void RecalcColliderPosition() = 0;
    virtual void Update() = 0;
    virtual ~IGameObject() {};

protected:
    IPosition * _position;
    ICollider * _collider;
    ObjectType _objectType;
    IMap * _map; // Map to which GameObject belongs
    int _id; // Id of object whithin the map
};

#endif
