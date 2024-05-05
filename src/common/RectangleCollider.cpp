/**
 * @file RectangleCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Implementation of GameObject's Rectangle Collider.
 */

#include "../headers/RectangleCollider.h"

RectangleCollider::RectangleCollider(int x, int y, int angle, int width, int height) {
    this->_position = new Position(x, y, angle);
    this->_colliderType = ect_rectangle_collider;
    this->_width = width;
    this->_height = height;
}

bool RectangleCollider::CheckCollision(ICollider * collider) {
    return false; // TODO
}

int RectangleCollider::GetWidth() {
    return this->_width;
}

void RectangleCollider::SetWidth(int width) {
    this->_width = width;
}

int RectangleCollider::GetHeight() {
    return this->_height;
}

void RectangleCollider::SetHeight(int height) {
    this->_height = height;
}
