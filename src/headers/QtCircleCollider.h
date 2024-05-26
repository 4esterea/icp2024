/**
 * @file QtCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Qt Collider.
 */

#ifndef __QTCIRCLECOLLIDER_H__
#define __QTCIRCLECOLLIDER_H__

#include <cmath>
#include "../interfaces/IQtCircleCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

class QtCircleCollider : public IQtCircleCollider {
    public:
        QtCircleCollider(double x, double y, double radius);
        IPosition * GetPosition();
        void SetCoords(double x, double y);
        double GetRadius();
        void SetRadius(double radius);
        bool CheckCollision(ICollider * collider);
        ~QtCircleCollider() {};
};

#endif
