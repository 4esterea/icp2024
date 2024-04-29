/**
 * @file ICircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Circle Collider interface
 */

#ifndef __ICIRCLECOLLIDER_H__
#define __ICIRCLECOLLIDER_H__

#include "ICollider.h"

using namespace std;

class ICircleCollider : public ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~ICircleCollider() {};

    private:
        double _radius;
};

#endif
