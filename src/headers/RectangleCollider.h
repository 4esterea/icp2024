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

class RectangleCollider : public IRectangleCollider {
    public:
        RectangleCollider(int x, int y, int angle, int width, int height);
        int GetWidth();
        void SetWidth(int width);
        int GetHeight();
        void SetHeight(int height);
        bool CheckCollision(ICollider * collider);
};

#endif
