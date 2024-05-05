/**
 * @file Position.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Implementation of GameObject's position.
 */

#include "../headers/Position.h"

Position::Position(int x, int y, int angle) {
    this->x = x;
    this->y = y;
    this->angle = angle;
}

void Position::SetPosition(int x, int y, int angle) {
    this->x = x;
    this->y = y;
    this->angle = angle;
}

void Position::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::SetPosition(IPosition * position) {
    this->x = position->x;
    this->y = position->y;
    this->angle = position->angle;
}
