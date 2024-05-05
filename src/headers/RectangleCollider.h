/**
 * @file RectangleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Declaration of Rectangle Collider.
 */

#ifndef __RECTANGLECOLLIDER_H__
#define __RECTANGLECOLLIDER_H__

#include "../interfaces/IRectangleCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

class RectangleCollider : public IRectangleCollider {
    public:
        RectangleCollider(double x, double y, double angle, double width, double height);
        double GetWidth();
        void SetWidth(double width);
        double GetHeight();
        void SetHeight(double height);
        bool CheckCollision(ICollider * collider);
};

#endif
