/**
 * @file ControlledRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief ControlledRobot common implementation.
 */

#include "../headers/ControlledRobot.h"
#include "../headers/Map.h"

ControlledRobot::ControlledRobot(double x, double y, double angle, double radius) {
    this->_collider = new QtCircleCollider(x, y, radius);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_controlled_robot;
    this->_speedDirection = esd_none;
    this->_rotationDirection = erd_none;
    this->_radius = radius;
    this->_speed = SIMRULE_ROBOT_DEFAULT_SPEED;
    this->_rotationAngle = SIMRULE_ROBOT_DEFAULT_ANGLE;
    this->_vision = new QtRectCollider(0,0,0,0,0);
}

double ControlledRobot::GetSpeed() {
    return this->_speed;
}

void ControlledRobot::RecalcColliderPosition() {
    // this->_collider->GetPosition()->SetPosition(this->_position->x, this->_position->y, this->_position->angle);
    // this->_vision->GetPosition()->SetPosition(this->_position->x, this->_position->y, this->_position->angle);
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
    Position pos = *(dynamic_cast<Position *>(this->GetPosition()));

    if (this->_speedDirection == esd_forward) {
        // Object movement
        this->GetPosition()->x = this->GetPosition()->x + this->GetSpeed() * cos(this->GetPosition()->angle * PI / 180);
        this->GetPosition()->y = this->GetPosition()->y + this->GetSpeed() * sin(this->GetPosition()->angle * PI / 180);
    }
    if (this->_rotationDirection == erd_right) {
        this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + this->_rotationAngle), 360);
    }
    if (this->_rotationDirection == erd_left) {
        this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + (360 - this->_rotationAngle)), 360);
    }
    // Collision checks
    for (uint64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
        IGameObject * go = this->_map->getGameObjects()[i];
        if (this->_id == go->GetId()) {
            // Skip if the same object
            continue;
        }
        if (this->_vision->CheckCollision(go->GetCollider())) {// || this->GetCollider()->CheckCollision(go->GetCollider())) {
            // Collision detected -> move object back
            this->GetPosition()->SetPosition(pos.x, pos.y);
            break;
        }
    }
    this->RecalcColliderPosition();
}
