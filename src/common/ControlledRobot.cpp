/**
 * @file ControlledRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief ControlledRobot common implementation.
 */

#include "../headers/ControlledRobot.h"

ControlledRobot::ControlledRobot(double x, double y, double angle, double radius) {
    this->_collider = new CircleCollider(x, y, angle, radius);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_controlled_robot;
    this->_speedDirection = esd_none;
    this->_rotationDirection = erd_none;
}

SpeedDirection ControlledRobot::GetSpeedDirection() {
    return this->_speedDirection;
}

void ControlledRobot::SetSpeedDirection(SpeedDirection speedDirection) {
    this->_speedDirection = speedDirection;
}

RotationDirection ControlledRobot::GetRotationDirection() {
    return this->_rotationDirection;
}

void ControlledRobot::SetRotationDirection(RotationDirection rotationDirection) {
    this->_rotationDirection = rotationDirection;
}

void ControlledRobot::Update() {
    // TODO
}
