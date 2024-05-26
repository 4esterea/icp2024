/**
 * @file Obstacle.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Common Obstacle declaration.
 */

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include <cstdint>
#include "../interfaces/IObstacle.h"
#include "../headers/RectangleCollider.h"
#include "../headers/QtRectCollider.h"
#include "../headers/Position.h"
#include "types.h"

class Obstacle: public IObstacle {
    public:
        Obstacle(double x, double y, double angle, double width, double height);
        void RecalcColliderPosition();
        void Update();
};

#endif
