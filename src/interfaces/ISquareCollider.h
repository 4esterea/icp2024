/**
 * @file ISquareCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Square Collider interface
 */

#ifndef __SQUAREICOLLIDER_H__
#define __SQUAREICOLLIDER_H__

#include "ICollider.h"

class ISquareCollider : public ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~ISquareCollider() {};

    private:
        double _sideLength;
};

#endif
