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

/**
 * @brief The IGameObject class Object of simulation
 */
class IGameObject {
public:
    /**
     * @brief GetCollider Returns collider assinged to the object
     * @return Collider
     */
    ICollider * GetCollider() { return this->_collider; };
    /**
     * @brief GetPosition Returns position of the object
     * @return Position
     */
    IPosition * GetPosition() { return this->_position; };
    /**
     * @brief GetObjectType Returns object type
     * @return Type of the object
     */
    ObjectType GetObjectType() { return this->_objectType; };
    /**
     * @brief SetMap Assignes map on which object is currently located
     * @param map Map
     */
    void SetMap(IMap * map) { this->_map = map; }
    /**
     * @brief GetId Returns id of the object
     * @return ID
     */
    int GetId() { return this->_id; }
    /**
     * @brief SetId Sets id of the object
     * @param id New id
     */
    void SetId(int id) { this->_id = id; }
    /**
     * @brief RecalcColliderPosition Recalculates relative collider positions
     */
    virtual void RecalcColliderPosition() = 0;
    /**
     * @brief Update Updates gameobject
     */
    virtual void Update() = 0;
    /**
     * @brief ~IGameObject Virtual desctructor
     */
    virtual ~IGameObject() {};

protected:
    IPosition * _position;
    ICollider * _collider;
    ObjectType _objectType;
    IMap * _map; // Map to which GameObject belongs
    int _id; // Id of object whithin the map
};

#endif
