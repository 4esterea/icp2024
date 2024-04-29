/**
 * @file ICollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Collider interface
 */

#ifndef __ICOLLIDER_H__
#define __ICOLLIDER_H__

#include "IPosition.h"

using namespace std;

class ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual IPosition * GetPosition() = 0;
        virtual ~ICollider() {};

    protected:
        IPosition * _position;
};

#endif
