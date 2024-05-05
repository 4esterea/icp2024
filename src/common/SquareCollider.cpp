/**
 * @file SquareCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Implementation of GameObject's Square Collider.
 */

#include "../headers/SquareCollider.h"

SquareCollider::SquareCollider(double x, double y, double angle, double sideLength) {
    this->_position = new Position(x, y, angle);
    this->_colliderType = ect_square_collider;
    this->_sideLength = sideLength;
}

bool SquareCollider::CheckCollision(ICollider * collider) {
    return false; // TODO
}

double SquareCollider::GetSideLength() {
    return this->_sideLength;
}

void SquareCollider::SetSideLength(double SquareCollider) {
    this->_sideLength = SquareCollider;
}
