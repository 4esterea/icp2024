/**
 * @file CircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Circle Collider.
 */

#ifndef __CIRCLECOLLIDER_H__
#define __CIRCLECOLLIDER_H__

#include <cmath>
#include "../interfaces/ICircleCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

class CircleCollider : public ICircleCollider {
    public:
        CircleCollider(double x, double y, double angle, double radius);
        double GetRadius();
        void SetRadius(double radius);
        bool CheckCollision(ICollider * collider);
};

#endif
