/**
 * @file IRectangleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Rectangle Collider interface
 */

#ifndef __IRECTANGLECOLLIDER_H__
#define __IRECTANGLECOLLIDER_H__

#include "ICollider.h"

using namespace std;

class IRectangleCollider : public ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~IRectangleCollider() = 0;

    private:
        float _width;
        float _height;
};

#endif