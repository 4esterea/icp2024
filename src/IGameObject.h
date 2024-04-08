/**
 * @file IGameObject.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Game Object interface
 */

#include "IPosition.h"
#include "ICollider.h"
#include "types.h"

using namespace std;

class IGameObject {
    public:
        virtual ICollider * GetCollider() = 0;
        virtual IPosition * GetPosition() = 0;
        virtual void Update() = 0;
        virtual ~IGameObject() = 0;

    private:
        IPosition * _position;
        ICollider * _collider;
        ObjectType _objectType;
};