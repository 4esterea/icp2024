#include "Viewport.h"
#include "src/headers/Map.h"
#include "src/headers/Obstacle.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include "src/ui/HoverableObstacle.h"

Viewport::Viewport(QWidget* parent, Map* map) : QGraphicsView(parent), _map(map) {
    this->scene = new QGraphicsScene(this);
    this->setScene(this->scene);
    scene->setBackgroundBrush(QBrush(Qt::black));
}
void Viewport::setMap(Map *map)
{
    this->_map = map;
}

void Viewport::drawAll() {
    if (this->_map != nullptr) {
        for (auto& gameObject : this->_map->GetGameObjects()) {
            auto obstacle = dynamic_cast<Obstacle*>(gameObject);
            if (obstacle) {
                auto position = obstacle->GetPosition();
                auto collider = obstacle->GetCollider();
                auto obstacleRect = new HoverableObstacle();
                obstacleRect->setRect(position->x, position->y, collider->GetWidth(), collider->GetHeight());
                obstacleRect->setPen(QPen({Qt::white, 2}));
                obstacleRect->setTransformOriginPoint(collider->GetWidth() / 2, collider->GetHeight() / 2);
                obstacleRect->setRotation(position->angle);
                obstacleRect->setFlag(QGraphicsItem::ItemIsMovable);
                this->scene->addItem(obstacleRect);
            }

            // TODO

        }
    }
}
