/**
 * @file CollisionChecker.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 04.05.2024
 * @brief Static class for collision checks.
 */

#ifndef __COLLISIONCHECKER_H__
#define __COLLISIONCHECKER_H__

#include <cmath>
#include "../interfaces/ICollider.h"
#include "../interfaces/ICircleCollider.h"
#include "../interfaces/IRectangleCollider.h"
#include "Position.h"

class CollisionChecker {
    public:
        static bool CheckCollision(ICollider * c1, ICollider * c2);
        static bool CheckCollisionCircleCircle(ICircleCollider * cc1, ICircleCollider * cc2);
        static bool CheckCollisionRectangleRectangle(IRectangleCollider * cr1, IRectangleCollider * cr2);
        static bool CheckCollisionRectangleCircle(IRectangleCollider * cr1, ICircleCollider * cc2);
};

#endif
