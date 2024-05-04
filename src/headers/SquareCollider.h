/**
 * @file SquareCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Declaration of Square Collider.
 */

#ifndef __SQUARECOLLIDER_H__
#define __SQUARECOLLIDER_H__

#include "../interfaces/ISquareCollider.h"
#include "Position.h"

class SquareCollider : public ISquareCollider {
    public:
        SquareCollider(int x, int y, int angle, int sideLength);
        int GetSideLength();
        void SetSideLength(int sideLength);
        bool CheckCollision(ICollider * collider);
};

#endif
