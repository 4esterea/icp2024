/**
 * @file CircleCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief Implementation of Circle Collider.
 */

#include "../headers/CircleCollider.h"

CircleCollider::CircleCollider(int x, int y, int angle, int radius) {
    this->_position = new Position(x, y, angle);
    this->_colliderType = ect_circle_collider;
    this->_radius = radius;
}

bool CircleCollider::CheckCollision(ICollider * collider) {
    return false; // TODO
}

int CircleCollider::GetRadius() {
    return this->_radius;
}

void CircleCollider::SetRadius(int radius) {
    this->_radius = radius;
}
