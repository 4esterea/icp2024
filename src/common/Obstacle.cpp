/**
 * @file Obstacle.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Obstacle implementation.
 */

#include "../headers/Obstacle.h"

#include "../headers/Map.h"

Obstacle::Obstacle(double x, double y, double angle, double width, double height) {
    this->_collider = new RectangleCollider(x, y, angle, width, height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_obstacle;
}

void Obstacle::RecalcColliderPosition() {
    this->_collider->GetPosition()->SetPosition(this->_position->x, this->_position->y, this->_position->angle);
}

void Obstacle::Update() {}
