#include "Viewport.h"
#include "src/headers/Map.h"
#include "src/headers/Obstacle.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include "src/ui/ObstacleGraphicItem.h"
#include <QMouseEvent>
#include "../mainwindow.h"

Viewport::Viewport(QWidget* parent, Map* map) : QGraphicsView(parent), _map(map) {
    this->resize(1000, 700);
    this->scene = new QGraphicsScene(this);
    this->scene->setSceneRect(0, 0, this->width(), this->height());
    this->scene->setBackgroundBrush(QBrush(Qt::black));
    this->setScene(this->scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}


void Viewport::setMap(Map *map)
{
    this->_map = map;
}

void Viewport::drawAll() {
    qDebug() << "Drawing...";
    this->scene->clear();
    if (this->_map != nullptr) {
        for (auto& gameObject : this->_map->getGameObjects()) {
            auto obstacle = dynamic_cast<Obstacle*>(gameObject);
            if (obstacle) {
                auto obstacleRect = new ObstacleGraphicItem(this, nullptr, obstacle);
                this->scene->addItem(obstacleRect);
                qDebug() << "The scene contains " << this->scene->items().count() << " obstacles";
            }
            // TODO

        }
    }
}

void Viewport::mousePressEvent(QMouseEvent *event) {
    QPointF pt = mapToScene(event->pos());
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());

    if (mainWindow && mainWindow->isObstacleMode()) {
        qDebug() << "Obstacle is being placed at " << pt.x() << " : " << pt.y();
        Obstacle* object = new Obstacle(pt.x(), pt.y(), 0, 50, 50);
        ObstacleGraphicItem* projection = new ObstacleGraphicItem(this, nullptr, object);
        _map->AddGameObject(object);
        this->scene->addItem(projection);
        this->update();

    }
    QGraphicsView::mousePressEvent(event);
}