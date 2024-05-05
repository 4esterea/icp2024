/**
 * @file CircleCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief Implementation of Circle Collider.
 */

#include "../headers/CircleCollider.h"

CircleCollider::CircleCollider(double x, double y, double angle, double radius) {
    this->_position = new Position(x, y, angle);
    this->_colliderType = ect_circle_collider;
    this->_radius = radius;
}

#include <QDebug>
bool CircleCollider::CheckCollision(ICollider * collider) {
    return CollisionChecker::CheckCollision(this, collider);
}

double CircleCollider::GetRadius() {
    return this->_radius;
}

void CircleCollider::SetRadius(double radius) {
    this->_radius = radius;
}
