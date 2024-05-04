/**
 * @file AutoRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief AutoRobot common implementation.
 */

#include "../headers/AutoRobot.h"

#include "../headers/Map.h" // If put in header Qt Creator uses 100% CPU (recursive)

AutoRobot::AutoRobot(int x, int y, int angle, int radius) {
    this->_collider = new CircleCollider(x, y, angle, radius);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_auto_robot;
    // TODO Add collision boxes
}

int AutoRobot::GetSpeed() {
    return this->_speed;
}

void AutoRobot::SetSpeed(int speed) {
    this->_speed = speed;
}

int AutoRobot::GetRotationAngle() {
    return this->_rotationAngle;
}

void AutoRobot::SetRotationAngle(int rotationAngle) {
    this->_rotationAngle = rotationAngle;
}

void AutoRobot::Update() {
}

