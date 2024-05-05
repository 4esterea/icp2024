/**
 * @file SquareCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Square Collider.
 */

#ifndef __SQUARECOLLIDER_H__
#define __SQUARECOLLIDER_H__

#include "../interfaces/ISquareCollider.h"
#include "Position.h"

class SquareCollider : public ISquareCollider {
    public:
        SquareCollider(double x, double y, double angle, double sideLength);
        double GetSideLength();
        void SetSideLength(double sideLength);
        bool CheckCollision(ICollider * collider);
};

#endif
