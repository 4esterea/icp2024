#include "Viewport.h"
#include "src/headers/Map.h"
#include "src/headers/Obstacle.h"
#include "src/headers/AutoRobot.h"
#include "src/headers/ControlledRobot.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include "src/ui/ObstacleGraphicItem.h"
#include "src/ui/RobotGraphicItem.h"
#include <QMouseEvent>
#include "../mainwindow.h"
#include <QPainter>

Viewport::Viewport(QWidget* parent, Map* map) : QGraphicsView(parent), _map(map) {

    this->resize(1000, 700);
    this->scene = new QGraphicsScene(this);
    this->scene->setSceneRect(0, 0, this->width(), this->height());
    this->scene->setBackgroundBrush(QBrush(Qt::black));
    this->setScene(this->scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void Viewport::drawAll() {
    qDebug() << "Drawing...";
    this->scene->clear();
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());
    auto map = mainWindow->getMap();
    if (map != nullptr) {
        auto mapSize = map->getSize();
        this->scene->setSceneRect(0, 0, mapSize.first, mapSize.second);
        this->fitInView(this->scene->sceneRect(), Qt::KeepAspectRatio);
        QGraphicsRectItem* bounds = new QGraphicsRectItem(this->scene->sceneRect());
        bounds->setPen(QPen({Qt::white, 2}));
        this->scene->addItem(bounds);
        for (auto& gameObject : map->getGameObjects()) {
            switch (gameObject->GetObjectType()) {
                case eot_gameobject: continue;
                case eot_obstacle: {
                    auto obstacle = dynamic_cast<Obstacle*>(gameObject);
                    if (obstacle) {
                        auto obstacleRect = new ObstacleGraphicItem(this, nullptr, obstacle);
                        this->scene->addItem(obstacleRect);
                    }
                    break;
                }
                case eot_auto_robot: {
                    auto autoRobot = dynamic_cast<AutoRobot *>(gameObject);
                    if (autoRobot) {
                        auto autoRobotItem = new RobotGraphicItem(this, nullptr, autoRobot);
                        this->scene->addItem(autoRobotItem);
                    }
                    break;
                }
                case eot_controlled_robot: {
                    auto controlledRobot = dynamic_cast<ControlledRobot *>(gameObject);
                    if (controlledRobot) {
                        auto controlledRobotItem = new RobotGraphicItem(this, nullptr, controlledRobot);
                        this->scene->addItem(controlledRobotItem);
                    }
                    break;
                }
            }
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
            QGraphicsView::mousePressEvent(event);
        } else if (mainWindow && mainWindow->isAutoRobotMode()) {
            qDebug() << "AutoRobot is being placed at " << pt.x() << " : " << pt.y();
            AutoRobot* object = new AutoRobot(pt.x(), pt.y(), 0, 50);
            RobotGraphicItem* projection = new RobotGraphicItem(this, nullptr, object);
            projection->setPos(pt);
            mainWindow->getMap()->AddGameObject(object);
            this->scene->addItem(projection);
            this->update();
            QGraphicsView::mousePressEvent(event);
        } else if (mainWindow && mainWindow->isRCRobotMode() && !_isRCRobotPlaced) {
            _isRCRobotPlaced = true;
            qDebug() << "RCRobot is being placed at " << pt.x() << " : " << pt.y();
            ControlledRobot* object = new ControlledRobot(pt.x(), pt.y(), 0, 50);
            RobotGraphicItem* projection = new RobotGraphicItem(this, nullptr, object);
            projection->setPos(pt);
            mainWindow->getMap()->AddGameObject(object);
            this->scene->addItem(projection);
            this->update();
            QGraphicsView::mousePressEvent(event);
        } else if (mainWindow && mainWindow->isRCRobotMode() && _isRCRobotPlaced) {
           qDebug() << "You can't place more than one RCRobot";
            QMessageBox::warning(this, "Warning", "You can't place more than one RCRobot");
           return;
        }
    } else if (event->button() == Qt::RightButton) {
        hideAllSettings();
        MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());
        if (mainWindow) {
            mainWindow->setDefaultEditingState();
        }
    }
}

void Viewport::hideAllSettings() {

    for (auto& item : this->scene->items()) {
        auto obstacle = dynamic_cast<ObstacleGraphicItem*>(item);
        if (obstacle) {
            auto settings = obstacle->getSettings();
            if (settings) settings->hide();
        }

        auto robot = dynamic_cast<RobotGraphicItem*>(item);
        if (robot) {
            auto settings = robot->getSettings();
            if (settings) settings->hide();
        }
    }
}

void Viewport::Update() {
    for (auto& item : this->scene->items()) {
        auto robotGraphic = dynamic_cast<RobotGraphicItem*>(item);
        if (robotGraphic) {
            robotGraphic->Update();
        }
    }
    this->update();
}


void Viewport::wheelEvent(QWheelEvent *event) {
    // if (event->delta() > 0) {
    //     scale(1.15, 1.15);
    // } else {
    //     scale(0.85, 0.85);
    // }
    // QGraphicsView::wheelEvent(event);
}
