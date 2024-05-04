/**
 * @file AutoRobot.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief AutoRobot common implementation.
 */

#include "../headers/AutoRobot.h"

#include "../headers/Map.h" // If put in header Qt Creator uses 100% CPU (recursive)

AutoRobot::AutoRobot(double x, double y, double angle, double radius) {
    this->_collider = new CircleCollider(x, y, angle, radius);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_auto_robot;
    // TODO Add collision boxes
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
    IMap * map = dynamic_cast<Map *>(this->_map);

    // Object movement
    this->GetPosition()->angle = std::fmod((this->GetPosition()->angle + this->_rotationAngle), 360);
    this->GetPosition()->x = this->GetPosition()->x + this->GetSpeed() * cos(this->GetPosition()->angle * PI / 180);
    this->GetPosition()->y = this->GetPosition()->y + this->GetSpeed() * sin(this->GetPosition()->angle * PI / 180);
    // Collision checks
    for (int64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
        IGameObject * go = this->_map->getGameObjects()[i];
        if (this->_id == go->GetId()) {
            // Skip if the same object
            continue;
        }
        qDebug() << "R" << this->GetId() << ": Check.";
        if (go->GetCollider()->CheckCollision(this->GetCollider())) {
            // Collision detected -> move object back
            this->GetPosition()->SetPosition(pos.x, pos.y);
            break;
        }
    }
    // Move colliders respectively
    this->GetCollider()->GetPosition()->SetPosition(this->GetPosition()->x, this->GetPosition()->y, this->GetPosition()->angle);
}

