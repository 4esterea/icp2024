/**
 * @file Position.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Implementation of GameObject's position.
 */

#include "../headers/Position.h"

Position::Position(double x, double y, double angle) {
    this->x = x;
    this->y = y;
    this->angle = angle;
}

void Position::SetPosition(double x, double y, double angle) {
    this->x = x;
    this->y = y;
    this->angle = angle;
}

void Position::SetPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

void Position::SetPosition(IPosition * position) {
    this->x = position->x;
    this->y = position->y;
    this->angle = position->angle;
}
