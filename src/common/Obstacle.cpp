/**
 * @file Obstacle.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Obstacle implementation.
 */

#include "../headers/Obstacle.h"

#include "../headers/Map.h" // If put in header Qt Creator uses 100% CPU (recursive)

Obstacle::Obstacle(double x, double y, double angle, double width, double height) {
    this->_collider = new RectangleCollider(x, y, angle, width, height);
    this->_position = new Position(x, y, angle);
    this->_objectType = eot_obstacle;
}

void Obstacle::Update() {
    for (int64_t i = 0; i < this->_map->getGameObjects().size(); i++) {
        IGameObject * go = this->_map->getGameObjects()[i];
        if (this->_id == go->GetId()) {
            // Skip if the same object
            continue;
        }
        qDebug() << "R" << this->GetId() << ": Check " << go->GetObjectType();
        if (this->GetCollider()->CheckCollision(go->GetCollider())) {
            // Collision detected -> move object back
            qDebug() << "x1 " << this->GetPosition()->x;
            break;
        }
    }
}
