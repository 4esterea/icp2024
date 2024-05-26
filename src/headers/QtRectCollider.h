/**
 * @file QtCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Qt Collider.
 */

#ifndef __QTRECTCOLLIDER_H__
#define __QTRECTCOLLIDER_H__

#include <cmath>
#include "../interfaces/IQtRectCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

class QtRectCollider : public IQtRectCollider {
    public:
        QtRectCollider(double x, double y, double angle, double width, double height);
        IPosition * GetPosition();
        void SetCoords(double x, double y);
        double GetWidth();
        void SetWidth(double width);
        double GetHeight();
        void SetHeight(double height);
        double GetAngle();
        void SetAngle(double angle);
        bool CheckCollision(ICollider * collider);
};

#endif
