/**
 * @file Position.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Declaration of GameObject's position.
 */

#ifndef __RECTANGLECOLLIDER_H__
#define __RECTANGLECOLLIDER_H__

#include "../interfaces/IRectangleCollider.h"
#include "Position.h"

class RectangleCollider : public IRectangleCollider {
    public:
        RectangleCollider(double x, double y, double angle, double width, double height);
        bool CheckCollision(ICollider * collider);
        double GetWidth();
        double GetHeight();
        IPosition * GetPosition();
};

#endif
