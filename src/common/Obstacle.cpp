/**
 * @file Obstacle.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Obstacle implementation.
 */

#include "../headers/Obstacle.h"

Obstacle::Obstacle(int x, int y, int angle, int width, int height) {
    this->_collider = new RectangleCollider(x, y, angle, width, height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_obstacle;
}

void Obstacle::Update() {
    // TODO
}
