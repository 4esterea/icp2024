/**
 * @file Obstacle.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Obstacle implementation.
 */

#include "../headers/Obstacle.h"

Obstacle::Obstacle(double x, double y, double angle, double width, double height) {
    this->_collider = new RectangleCollider(x, y, angle, width, height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_obstacle;
}

IRectangleCollider * Obstacle::GetCollider() {
    return this->_collider;
}

IPosition * Obstacle::GetPosition() {
    return this->_position;
}

void Obstacle::Update() {
    // TODO
}

ObjectType Obstacle::GetObjectType() {
    return this->_objectType;
}

void Obstacle::UpdateCoords(int x, int y) {
    float angle = this->_position->angle;
    delete this->_position;
    this->_position = new Position(x, y, angle);
}


