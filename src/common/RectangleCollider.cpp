/**
 * @file RectangleCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Implementation of GameObject's Rectangle Collider.
 */

#include "../headers/RectangleCollider.h"

RectangleCollider::RectangleCollider(double x, double y, double angle, double width, double height) {
    this->_position = new Position(x, y, angle);
    this->_width = width;
    this->_height = height;
}

bool RectangleCollider::CheckCollision(ICollider * collider) {
    return false; // TODO
}

double RectangleCollider::GetWidth() {
    return this->_width;
}

double RectangleCollider::GetHeight() {
    return this->_height;
}

IPosition * RectangleCollider::GetPosition() {
    return this->_position;
}
