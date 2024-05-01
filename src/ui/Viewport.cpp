#include "Viewport.h"
#include "src/headers/Map.h"
#include "src/headers/Obstacle.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include "src/ui/HoverableObstacle.h"

Viewport::Viewport(QWidget* parent, Map* map) : QGraphicsView(parent), _map(map) , _objects(){
    this->resize(1000, 700);
    this->resetTransform();
    this->scene = new QGraphicsScene(this);
    this->scene->setSceneRect(0, 0, this->width(), this->height());
    this->scene->setBackgroundBrush(QBrush(Qt::black));
    this->setScene(this->scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qDebug() << "vw is " << this->width() << " vh is " << this->height();

}
void Viewport::setMap(Map *map)
{
    this->_map = map;
}

void Viewport::drawAll() {
    this->resetTransform();
    if (this->_map != nullptr) {
        for (auto& gameObject : this->_map->GetGameObjects()) {
            auto obstacle = dynamic_cast<Obstacle*>(gameObject);
            if (obstacle) {
                auto position = obstacle->GetPosition();
                auto collider = obstacle->GetCollider();
                auto obstacleRect = new HoverableObstacle(this);
                obstacleRect->setRect(position->x, position->y, collider->GetWidth(), collider->GetHeight());
                obstacleRect->setPen(QPen({Qt::white, 2}));
                obstacleRect->setTransformOriginPoint(collider->GetWidth() / 2, collider->GetHeight() / 2);
                obstacleRect->setRotation(position->angle);
                obstacleRect->setFlag(QGraphicsItem::ItemIsMovable);
                this->scene->addItem(obstacleRect);
                this->_objects.append(obstacleRect);
            }

            // TODO

        }
    }
}

