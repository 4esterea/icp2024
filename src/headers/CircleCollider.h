/**
 * @file CircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Declaration of Circle Collider.
 */

#ifndef __CIRCLECOLLIDER_H__
#define __CIRCLECOLLIDER_H__

#include "../interfaces/ICircleCollider.h"
#include "Position.h"

class CircleCollider : public ICircleCollider {
    public:
        CircleCollider(double x, double y, double angle, double radius);
        double GetRadius();
        void SetRadius(double radius);
        bool CheckCollision(ICollider * collider);
};

#endif
