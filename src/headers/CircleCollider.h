/**
 * @file CircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Circle Collider.
 */

#ifndef __CIRCLECOLLIDER_H__
#define __CIRCLECOLLIDER_H__

#include "../interfaces/ICircleCollider.h"
#include "Position.h"

class CircleCollider : public ICircleCollider {
    public:
        CircleCollider(int x, int y, int angle, int radius);
        int GetRadius();
        void SetRadius(int radius);
        bool CheckCollision(ICollider * collider);
};

#endif
