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


void Viewport::drawAll() {
    qDebug() << "Drawing...";
    this->scene->clear();
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());
    auto map = mainWindow->getMap();
    if (map != nullptr) {
        for (auto& gameObject : map->getGameObjects()) {
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
    if (event->button() == Qt::LeftButton) {
        QPointF pt = mapToScene(event->pos());
        MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());

        if (mainWindow && mainWindow->isObstacleMode()) {
            qDebug() << "Obstacle is being placed at " << pt.x() << " : " << pt.y();
            Obstacle* object = new Obstacle(pt.x(), pt.y(), 0, 50, 50);
            ObstacleGraphicItem* projection = new ObstacleGraphicItem(this, nullptr, object);
            mainWindow->getMap()->AddGameObject(object);
            this->scene->addItem(projection);
            this->update();

        }
        QGraphicsView::mousePressEvent(event);
    } else if (event->button() == Qt::RightButton) {
        MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());
        if (mainWindow) {
            mainWindow->setDefaultEditingState();
        }
    }
}

void Viewport::hideAllSettings() {
    qDebug() << "Hiding all settings:" << this->scene->items().count() << " items";

    for (auto& item : this->scene->items()) {
        auto obstacle = dynamic_cast<ObstacleGraphicItem*>(item);
        if (obstacle) {
            auto settings = obstacle->getSettings();
            if (settings) settings->hide();
        }
    }
}