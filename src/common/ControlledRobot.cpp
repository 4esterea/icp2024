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
    double rotationAngle = std::fmod(this->_rotationAngle * SIMRULE_FRAME_TIMEGAP_MS * this->_rotationDirection / 1000, 360);
    double speed = this->GetSpeed() * SIMRULE_FRAME_TIMEGAP_MS / 1000;
    bool isSight = false;
    bool isStuck = false;

    if (this->_speedDirection == esd_forward) {
        // Object movement
        this->GetPosition()->x = this->GetPosition()->x + speed * cos(this->GetPosition()->angle * PI / 180);
        this->GetPosition()->y = this->GetPosition()->y + speed * sin(this->GetPosition()->angle * PI / 180);
    }
    this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + rotationAngle), 360);
    // Collision checks
    for (uint64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
        IGameObject * go = this->_map->getGameObjects()[i];
        if (this->_id == go->GetId()) {
            // Skip if the same object
            continue;
        }
        if (this->_vision->CheckCollision(go->GetCollider())) {
            // Collision detected -> turn
            isSight = true;
        }
        if (this->GetCollider()->CheckCollision(go->GetCollider())){
            isStuck = true;
            break;
        }
    }
    if (isStuck && isSight) {
        // Collision detected -> move object back
        this->GetPosition()->SetPosition(pos.x, pos.y);
    }
    this->RecalcColliderPosition();
}
