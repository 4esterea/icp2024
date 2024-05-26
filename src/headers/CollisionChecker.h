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

/**
 * @brief The CollisionChecker class Static colllision checking class
 */
class CollisionChecker {
public:
    /**
     * @brief CheckCollision Checks collision between any 2 colliders
     * @param c1 Collider 1
     * @param c2 Collider 2
     * @return True if collide
     */
    static bool CheckCollision(ICollider * c1, ICollider * c2);
    /**
     * @brief CheckCollisionCircleCircle Checks collision between 2 circles
     * @param cc1 Circle collider 1
     * @param cc2 Circle collider 2
     * @return True if collider
     */
    static bool CheckCollisionCircleCircle(ICircleCollider * cc1, ICircleCollider * cc2);
    /**
     * @brief CheckCollisionRectangleRectangle Checks collision between 2 rectangles
     * @param cr1 Rectangle collider 1
     * @param cr2 Rectangle collider 2
     * @return True if collider
     */
    static bool CheckCollisionRectangleRectangle(IRectangleCollider * cr1, IRectangleCollider * cr2);
    /**
     * @brief CheckCollisionRectangleRectangle Checks collision between rectangle and circle
     * @param cr1 Rectangle collider 1
     * @param cc2 Circle collider 2
     * @return True if collider
     */
    static bool CheckCollisionRectangleCircle(IRectangleCollider * cr1, ICircleCollider * cc2);
private:
    /**
     * @brief IsLinesIntersect Checks if 2 lines intersects
     * @param l1p1 Point 1 on 1st line
     * @param l1p2 Point 2 on 1st line
     * @param l2p1 Point 1 on 2st line
     * @param l2p2 Point 2 on 2st line
     * @return True if intersects
     */
    static bool IsLinesIntersect(std::pair<double, double> l1p1, std::pair<double, double> l1p2, std::pair<double, double> l2p1, std::pair<double, double> l2p2);
    /**
     * @brief GetPointsOrientation Checks if points are oriented clockwise or counter clockwise
     * @param p1 Point 1
     * @param p2 Point 2
     * @param p3 Point 3
     * @return Orientation of points
     */
    static PointsOrientation GetPointsOrientation(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3);
    /**
     * @brief IsPointOnLine Checks if point lies on line
     * @param lp1 Point 1 on 1st line
     * @param lp2 Point 2 on 1st line
     * @param p Point
     * @return True if lies
     */
    static bool IsPointOnLine(std::pair<double, double> lp1, std::pair<double, double> lp2, std::pair<double, double> p);
};

#endif
