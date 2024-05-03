/**
 * @file AutoRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief AutoRobot common implementation.
 */

#include "../headers/AutoRobot.h"

AutoRobot::AutoRobot(double x, double y, double angle, double width, double height) {
    this->_collider = new RectangleCollider(x, y, angle, width, height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_autorobot;
}

void AutoRobot::Update() {
    // TODO
}
