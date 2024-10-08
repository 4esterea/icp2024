/**
 * @file ICircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
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
        virtual double GetRadius() = 0;
        virtual void SetRadius(double radius) = 0;
        virtual ~ICircleCollider() {};

    protected:
        double _radius;
};

#endif
