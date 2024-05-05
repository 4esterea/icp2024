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
#include "../headers/Position.h"
#include "types.h"

class Obstacle: public IObstacle {
    public:
    /**
    * @brief Constructor for the Obstacle class.
    *
    * @param x The initial x-coordinate of the obstacle.
    * @param y The initial y-coordinate of the obstacle.
    * @param angle The initial angle of the obstacle.
    * @param width The width of the obstacle.
    * @param height The height of the obstacle.
    */
    Obstacle(double x, double y, double angle, double width, double height);

    /**
     * @brief Recalculates the position of the obstacle's collider.
     */
    void RecalcColliderPosition();

    /**
     * @brief Updates the state of the obstacle.
     */
    void Update();
};

#endif
