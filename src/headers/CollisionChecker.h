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
#include "Position.h"

class CollisionChecker {
    public:
        /**
         * @brief CheckCollision Checks collision between 2 generic colliders
         * @param c1 Collider 1
         * @param c2 Collider 2
         * @return True if collide
         */
        static bool CheckCollision(ICollider * c1, ICollider * c2);

        /**
         * @brief CheckCollisionCircleCircle Checks collision between Circle and Circle
         * @param cc1 Circle Collider 1
         * @param cc2 Circle Collider 2
         * @return True if collide
         */
        static bool CheckCollisionCircleCircle(ICircleCollider * cc1, ICircleCollider * cc2);

        /**
         * @brief CheckCollisionRectangleRectangle Checks collision between Circle and Circle
         * @param cr1 Rectangle Collider 1
         * @param cr2 Rectangle Collider 2
         * @return
         */
        static bool CheckCollisionRectangleRectangle(IRectangleCollider * cr1, IRectangleCollider * cr2);

        /**
         * @brief CheckCollisionRectangleCircle Checks collision between Circle and Circle
         * @param cr1 Rectangle Collider 1
         * @param cc2 Circle Collider 2
         * @return
         */
        static bool CheckCollisionRectangleCircle(IRectangleCollider * cr1, ICircleCollider * cc2);
    private:
        /**
         * @brief IsLinesIntersect Checks if 2 lines intersect
         * @param l1p1 Start of line 1
         * @param l1p2 End of line 1
         * @param l2p1 Start of line 2
         * @param l2p2 End of line 2
         * @return
         */
        static bool IsLinesIntersect(std::pair<double, double> l1p1, std::pair<double, double> l1p2, std::pair<double, double> l2p1, std::pair<double, double> l2p2);

        /**
         * @brief GetPointsOrientation Finds points orientation agains each other
         * @param p1 Point 1
         * @param p2 Point 2
         * @param p3 Point 3
         * @return Collinear / Clockwise / Counter clockwise
         */
        static PointsOrientation GetPointsOrientation(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3);

        /**
         * @brief IsPointOnLine Checks if point is on the given line
         * @param lp1 Start of line
         * @param lp2 End of line
         * @param p Point
         * @return Is point on line
         */
        static bool IsPointOnLine(std::pair<double, double> lp1, std::pair<double, double> lp2, std::pair<double, double> p);
};

#endif
