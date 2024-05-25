/**
 * @file CollisionChecker.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 04.05.2024
 * @brief Static class for collision checks.
 */

#ifndef __COLLISIONCHECKER_H__
#define __COLLISIONCHECKER_H__

#include <cmath>
#include <vector>
#include "../interfaces/ICollider.h"
#include "../interfaces/ICircleCollider.h"
#include "../interfaces/IRectangleCollider.h"
#include "../interfaces/IQtRectCollider.h"
#include "../interfaces/IQtCircleCollider.h"
#include "Position.h"

class CollisionChecker {
    public:
        static bool CheckCollision(ICollider * c1, ICollider * c2);
        static bool CheckCollisionCircleCircle(ICircleCollider * cc1, ICircleCollider * cc2);
        static bool CheckCollisionRectangleRectangle(IRectangleCollider * cr1, IRectangleCollider * cr2);
        static bool CheckCollisionRectangleCircle(IRectangleCollider * cr1, ICircleCollider * cc2);
    private:
        static bool IsLinesIntersect(std::pair<double, double> l1p1, std::pair<double, double> l1p2, std::pair<double, double> l2p1, std::pair<double, double> l2p2);
        static PointsOrientation GetPointsOrientation(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3);
        static bool IsPointOnLine(std::pair<double, double> lp1, std::pair<double, double> lp2, std::pair<double, double> p);
};

#endif
