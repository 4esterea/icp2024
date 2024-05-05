/**
 * @file ControlledRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
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
    this->_speed = 0;
    this->_rotationAngle = 0;
}

double ControlledRobot::GetSpeed() {
    return this->_speed;
}

void ControlledRobot::RecalcColliderPosition() {
    this->_collider->GetPosition()->SetPosition(this->_position->x, this->_position->y, this->_position->angle);
}

void ControlledRobot::SetSpeed(double speed) {
    this->_speed = speed;
}

double ControlledRobot::GetRotationAngle() {
    return this->_rotationAngle;
}

void ControlledRobot::SetRotationAngle(double rotationAngle) {
    this->_rotationAngle = rotationAngle;
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
