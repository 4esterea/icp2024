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

/**
 * @brief The Obstacle class Basic obstacle
 */
class Obstacle: public IObstacle {
public:
    /**
     * @brief Obstacle Constructor of obstacle
     * @param x X coordinate
     * @param y Y coordinate
     * @param angle Angle of rotation
     * @param width Width
     * @param height Height
     */
    Obstacle(double x, double y, double angle, double width, double height);
    /**
     * @brief RecalcColliderPosition Recalculates relative collider positions
     */
    void RecalcColliderPosition();
    /**
     * @brief Update Updates obstacle
     */
    void Update();
};

#endif
