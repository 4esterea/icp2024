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
        virtual ICollider * GetCollider() = 0;
        virtual IPosition * GetPosition() = 0;
        virtual ObjectType GetObjectType() = 0;
        virtual void Update() = 0;
        virtual ~IGameObject() {};
        virtual void UpdateCoords(int x, int y) = 0;

    protected:
        IPosition * _position;
        ICollider * _collider;
        ObjectType _objectType;
};

#endif
