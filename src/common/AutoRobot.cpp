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
    this->SetSpeed(1);
    this->SetRotationAngle(1);
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
    Position pos = *(dynamic_cast<Position *>(this->GetPosition()));
    IMap * map = dynamic_cast<Map *>(this->_map);

    // Object movement
    // this->GetPosition()->angle += this->_rotationAngle;
    // this->GetPosition()->x = this->GetPosition()->x * (1+ ( (this->GetPosition()->angle - 90) * 2 * PI / 360) );
    this->GetPosition()->x += 1;
    // Collision checks
    // for (uint64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
    //     IGameObject * go = this->_map->getGameObjects()[i];
    //     if (this->_id == go->GetId()) {
    //         // Skip if the same object
    //         continue;
    //     }
    //     if (go->GetCollider()->CheckCollision(this->GetCollider())) {
    //         // Collision detected -> move object back
    //         this->GetPosition()->SetPosition(pos.x, pos.y, pos.angle);
    //         break;
    //     }
    // }
}

