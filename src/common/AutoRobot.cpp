/**
 * @file AutoRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief AutoRobot common implementation.
 */

#include "../headers/AutoRobot.h"

#include "../headers/Map.h"

AutoRobot::AutoRobot(double x, double y, double angle, double radius) {
    this->_collider = new QtCircleCollider(x, y, radius);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_auto_robot;
    this->_radius = radius;
    this->_speed = SIMRULE_ROBOT_DEFAULT_SPEED;
    this->_rotationAngle = SIMRULE_ROBOT_DEFAULT_ANGLE;
    this->_vision = new QtRectCollider(0,0,0,0,0);
    this->_collisionBehavior = erd_left;
}

void AutoRobot::RecalcColliderPosition() {
    // if (this->GetCollider()->GetGraphics() != nullptr) {
    //     this->_collider->SetCoords(this->_position->x, this->_position->y);
    // }
}

double AutoRobot::GetSpeed() {
    return this->_speed;
}

void AutoRobot::SetSpeed(double speed) {
    this->_speed = speed;
}

double AutoRobot::GetRotationAngle() {
    return this->_rotationAngle;
}

void AutoRobot::SetRotationAngle(double rotationAngle) {
    this->_rotationAngle = rotationAngle;
}

void AutoRobot::Update() {
    Position pos = *(dynamic_cast<Position *>(this->GetPosition()));
    bool isSight = false;

    // Object movement
    this->GetPosition()->x = this->GetPosition()->x + this->GetSpeed() * cos(this->GetPosition()->angle * PI / 180);
    this->GetPosition()->y = this->GetPosition()->y + this->GetSpeed() * sin(this->GetPosition()->angle * PI / 180);
    // // Move colliders respectively
    this->RecalcColliderPosition();
    // // Collision checks
    for (uint64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
        IGameObject * go = this->_map->getGameObjects()[i];
        if (this->_id == go->GetId()) {
            // Skip if the same object
            continue;
        }
        if (this->GetCollider()->CheckCollision(go->GetCollider())){
            // Collision detected -> move object back
            if (SIMRULE_ROTATE_IF_STUCK) {
                this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + this->_rotationAngle / 4), 360); // /4 so robot will rotate slower when hit
            }
            this->GetPosition()->SetPosition(pos.x, pos.y);
            // Move colliders respectively
            this->RecalcColliderPosition();
            isSight = false;
            break;
        }
        if (this->_vision->CheckCollision(go->GetCollider())) {
            // Collision detected -> turn
            isSight = true;
        }
    }
    if (isSight) {
        this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + this->_rotationAngle), 360) * this->_collisionBehavior;
    }
    this->RecalcColliderPosition();
}

