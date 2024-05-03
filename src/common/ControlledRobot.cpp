/**
 * @file ControlledRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief ControlledRobot common implementation.
 */

#include "../headers/ControlledRobot.h"

ControlledRobot::ControlledRobot(double x, double y, double angle, double width, double height) {
    this->_collider = new RectangleCollider(x, y, angle, width, height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_controlled_robot;
    this->_speedDirection = esd_none;
    this->_rotationDirection = erd_none;
}

void ControlledRobot::Update() {
    // TODO
}

void ControlledRobot::SetSpeedDirection(SpeedDirection speedDirection) {
    this->_speedDirection = speedDirection;
}

void ControlledRobot::SetRotationDirection(RotationDirection rotationDirection) {
    this->_rotationDirection = rotationDirection;
}
