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
    this->_collider = new CircleCollider(x, y, angle, radius);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_auto_robot;
    this->_speed = 0;
    this->_rotationAngle = 0;

    // TODO Add collision boxes
}

void AutoRobot::RecalcColliderPosition() {
    this->_collider->GetPosition()->SetPosition(this->_position->x, this->_position->y, this->_position->angle);
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

#include <QDebug>
void AutoRobot::Update() {
    Position pos = *(dynamic_cast<Position *>(this->GetPosition()));

    // Object movement
    this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + this->_rotationAngle), 360);
    this->GetPosition()->x = this->GetPosition()->x + this->GetSpeed() * cos(this->GetPosition()->angle * PI / 180);
    this->GetPosition()->y = this->GetPosition()->y + this->GetSpeed() * sin(this->GetPosition()->angle * PI / 180);
    // Move colliders respectively
    this->GetCollider()->GetPosition()->SetPosition(this->GetPosition()->x, this->GetPosition()->y, this->GetPosition()->angle);
    // Collision checks
    for (uint64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
        IGameObject * go = this->_map->getGameObjects()[i];
        if (this->_id == go->GetId()) {
            // Skip if the same object
            continue;
        }
        qDebug() << "R" << this->GetId() << ": Check " << go->GetObjectType();
        if (this->GetCollider()->CheckCollision(go->GetCollider())) {
            // Collision detected -> move object back
            qDebug() << "x1 " << this->GetPosition()->x << "x2 " << pos.x;
            this->GetPosition()->SetPosition(pos.x, pos.y);
            // Move colliders respectively
            this->GetCollider()->GetPosition()->SetPosition(pos.x, pos.y, this->GetPosition()->angle);
            break;
        }
    }
}

