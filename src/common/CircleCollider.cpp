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

bool CircleCollider::CheckCollision(ICollider * collider) {
    switch (collider->GetColliderType()) {
        case ect_collider: return false;
        case ect_circle_collider: {
            CircleCollider * cr = dynamic_cast<CircleCollider *>(collider);
            return sqrt(pow(abs(this->GetPosition()->x - cr->GetPosition()->x), 2) + pow(abs(this->GetPosition()->y - cr->GetPosition()->y), 2)) < (this->GetRadius() + cr->GetRadius());
        }
        case ect_rectangle_collider: return false; // TODO
        case ect_square_collider: return false; // TODO
    }

    return false; // TODO
}

double CircleCollider::GetRadius() {
    return this->_radius;
}

void CircleCollider::SetRadius(double radius) {
    this->_radius = radius;
}
