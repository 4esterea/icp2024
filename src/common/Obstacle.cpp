/**
 * @file Obstacle.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Obstacle implementation.
 */

#include "../headers/Obstacle.h"

#include "../headers/Map.h"

Obstacle::Obstacle(double x, double y, double angle, double width, double height) {
    this->_width = width;
    this->_height = height;
    this->_collider = new QtRectCollider(x,y,angle,width,height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_obstacle;
}

void Obstacle::RecalcColliderPosition() {
    // if (this->_collider->GetGraphics() != nullptr) {
    //     qDebug() << this->_collider->GetPosition()->x << this->_collider->GetPosition()->y << this->_position->x << this->_position->y;
    //     this->_collider->SetCoords(this->_collider->GetPosition()->x, this->_collider->GetPosition()->y);
    //     this->_collider->SetAngle(this->_position->angle);
    // }
}

void Obstacle::Update() {
    // for (uint64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
    //     IGameObject * go = this->_map->getGameObjects()[i];
    //     if (this->_id == go->GetId()) {
    //         // Skip if the same object
    //         continue;
    //     }
    //     if (go->GetObjectType() == eot_obstacle) {
    //         qDebug() << dynamic_cast<IObstacle *>(go)->GetCollider()->GetAngle();
    //         if (this->_collider->CheckCollision(dynamic_cast<IObstacle *>(go)->GetCollider())) {
    //             qDebug() << "true";
    //         } else {
    //             qDebug() << "false";
    //         }
    //     }
    // }
}
