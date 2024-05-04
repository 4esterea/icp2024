/**
 * @file Obstacle.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Common Obstacle declaration.
 */

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "../interfaces/IObstacle.h"
#include "../headers/RectangleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class Obstacle: public IObstacle {
    public:
        Obstacle(int x, int y, int angle, int width, int height);
        void Update();
};

#endif
