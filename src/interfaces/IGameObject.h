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
    /**
     * @brief Gets the collider of the game object.
     *
     * @return A pointer to the collider of the game object.
     */
    ICollider * GetCollider();

    /**
     * @brief Gets the position of the game object.
     *
     * @return A pointer to the position of the game object.
     */
    IPosition * GetPosition();

    /**
     * @brief Gets the type of the game object.
     *
     * @return The type of the game object.
     */
    ObjectType GetObjectType();

    /**
     * @brief Sets the map of the game object.
     *
     * @param map A pointer to the map to set the game object to.
     */
    void SetMap(IMap * map);

    /**
     * @brief Gets the ID of the game object.
     *
     * @return The ID of the game object.
     */
    int GetId();

    /**
     * @brief Sets the ID of the game object.
     *
     * @param id The ID to set the game object to.
     */
    void SetId(int id);

    /**
     * @brief Recalculates the position of the collider of the game object.
     */
    virtual void RecalcColliderPosition() = 0;

    /**
     * @brief Updates the state of the game object.
     */
    virtual void Update() = 0;

    /**
     * @brief Virtual destructor for the IGameObject interface.
     */
    virtual ~IGameObject();

protected:
    IPosition * _position;
    ICollider * _collider;
    ObjectType _objectType;
    IMap * _map; // Map to which GameObject belongs
    int _id; // Id of object whithin the map
};

#endif
