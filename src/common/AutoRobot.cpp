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
    this->_collisionBehavior = erd_right;
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
    double rotationAngle = std::fmod(this->_rotationAngle * SIMRULE_FRAME_TIMEGAP_MS * this->_collisionBehavior / 1000, 360);
    double speed = this->GetSpeed() * SIMRULE_FRAME_TIMEGAP_MS / 1000;
    bool isSight = false;
    bool isStuck = false;

    // Object movement
    this->GetPosition()->x = this->GetPosition()->x + speed * cos(this->GetPosition()->angle * PI / 180);
    this->GetPosition()->y = this->GetPosition()->y + speed * sin(this->GetPosition()->angle * PI / 180);
    // // Move colliders respectively
    this->RecalcColliderPosition();
    // // Collision checks
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
    if (!SIMRULE_ROTATE_IF_STUCK) {
        if (isSight && !isStuck) {
            this->GetPosition()->angle = this->GetPosition()->angle + rotationAngle;
        }
    } else {
        if (isSight || isStuck) {
            this->GetPosition()->angle = this->GetPosition()->angle + rotationAngle;
        }
    }
    if (isStuck && isSight) {
        // Collision detected -> move object back
        this->GetPosition()->SetPosition(pos.x, pos.y);
    }
    this->RecalcColliderPosition();
}

