/**
 * @file SquareCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Implementation of GameObject's Square Collider.
 */

#include "../headers/SquareCollider.h"

SquareCollider::SquareCollider(int x, int y, int angle, int sideLength) {
    this->_position = new Position(x, y, angle);
    this->_colliderType = ect_square_collider;
    this->_sideLength = sideLength;
}

bool SquareCollider::CheckCollision(ICollider * collider) {
    return false; // TODO
}

int SquareCollider::GetSideLength() {
    return this->_sideLength;
}

void SquareCollider::SetSideLength(int SquareCollider) {
    this->_sideLength = SquareCollider;
}
