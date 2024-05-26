/**
* @file Viewport.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Implementation of Viewport
 */



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
#include <QPainter>

Viewport::Viewport(QWidget* parent, Map* map) : QGraphicsView(parent), _map(map) {

    this->resize(1000, 700);
    this->scene = new QGraphicsScene(this);
    this->scene->setSceneRect(0, 0, this->width(), this->height());
    this->scene->setBackgroundBrush(QBrush(Qt::black));
    this->setScene(this->scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    _mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());
}

void Viewport::drawAll() {
    qDebug() << "Drawing...";
    this->scene->clear();
    _isRCRobotPlaced = false;
    auto map = _mainWindow->getMap();
    if (map != nullptr) {
        auto mapSize = map->getSize();
        this->scene->setSceneRect(0, 0, mapSize.first, mapSize.second);
        this->fitInView(this->scene->sceneRect(), Qt::KeepAspectRatio);

        Obstacle* leftBoundary = new Obstacle(0, 0, 0, 1, mapSize.second);
        ObstacleGraphicItem* leftBoundaryProjection = new ObstacleGraphicItem(this, nullptr, leftBoundary);
        leftBoundary->GetCollider()->SetGraphics(leftBoundaryProjection);
        this->scene->addItem(leftBoundaryProjection);
        Obstacle* rightBoundary = new Obstacle(mapSize.first, 0, 0, 1, mapSize.second);
        ObstacleGraphicItem* rightBoundaryProjection = new ObstacleGraphicItem(this, nullptr, rightBoundary);
        rightBoundary->GetCollider()->SetGraphics(rightBoundaryProjection);
        this->scene->addItem(rightBoundaryProjection);
        Obstacle* topBoundary = new Obstacle(0, 0, 0, mapSize.first, 1);
        ObstacleGraphicItem* topBoundaryProjection = new ObstacleGraphicItem(this, nullptr, topBoundary);
        topBoundary->GetCollider()->SetGraphics(topBoundaryProjection);
        this->scene->addItem(topBoundaryProjection);
        Obstacle* bottomBoundary = new Obstacle(0, mapSize.second, 0, mapSize.first, 1);
        ObstacleGraphicItem* bottomBoundaryProjection = new ObstacleGraphicItem(this, nullptr, bottomBoundary);
        bottomBoundary->GetCollider()->SetGraphics(bottomBoundaryProjection);
        this->scene->addItem(bottomBoundaryProjection);
        this->update();

        map->AddGameObject(leftBoundary);
        map->AddGameObject(rightBoundary);
        map->AddGameObject(topBoundary);
        map->AddGameObject(bottomBoundary);

        for (auto& gameObject : map->getGameObjects()) {
            switch (gameObject->GetObjectType()) {
                case eot_gameobject: continue;
                case eot_obstacle: {
                    auto obstacle = dynamic_cast<Obstacle*>(gameObject);
                    if (obstacle) {
                        auto obstacleRect = new ObstacleGraphicItem(this, nullptr, obstacle);
                        obstacle->GetCollider()->SetGraphics(obstacleRect);
                        this->scene->addItem(obstacleRect);
                    }
                    break;
                }
                case eot_auto_robot: {
                    auto autoRobot = dynamic_cast<AutoRobot *>(gameObject);
                    if (autoRobot) {
                        auto autoRobotItem = new RobotGraphicItem(this, nullptr, autoRobot);
                        autoRobot->GetCollider()->SetGraphics(autoRobotItem);
                        this->scene->addItem(autoRobotItem);
                    }
                    break;
                }
                case eot_controlled_robot: {
                    auto controlledRobot = dynamic_cast<ControlledRobot *>(gameObject);
                    if (controlledRobot) {
                        auto controlledRobotItem = new RobotGraphicItem(this, nullptr, controlledRobot);
                        controlledRobot->GetCollider()->SetGraphics(controlledRobotItem);
                        this->scene->addItem(controlledRobotItem);
                        _isRCRobotPlaced = true;
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
        QRectF adjustedSceneRect = scene->sceneRect().adjusted(0, 0, -50, -50);
        if (!adjustedSceneRect.contains(pt)) {
            qDebug() << "Out of bounds";
            return;
        }
        QRectF rect(pt.x() - 25, pt.y() - 25, 50, 50);
        QList<QGraphicsItem*> itemsInRange = scene->items(rect);

        for (int i = 0; i < itemsInRange.size(); ++i) {
            QGraphicsItem* item = itemsInRange[i];
            if (dynamic_cast<QGraphicsRectItem*>(item) && !dynamic_cast<ObstacleGraphicItem*>(item)) {
                itemsInRange.removeAt(i);
                --i;
            }
        }

        if (!itemsInRange.isEmpty()) {
            return;
        }

        MainWindow* mainWindow = qobject_cast<MainWindow*>(this->parentWidget()->parentWidget());

        if (mainWindow && mainWindow->isObstacleMode()) {
            qDebug() << "Obstacle is being placed at " << pt.x() << " : " << pt.y();
            Obstacle* object = new Obstacle(pt.x(), pt.y(), 0, 50, 50);
            ObstacleGraphicItem* projection = new ObstacleGraphicItem(this, nullptr, object);
            object->GetCollider()->SetGraphics(projection);
            mainWindow->getMap()->AddGameObject(object);
            this->scene->addItem(projection);
            this->update();
            QGraphicsView::mousePressEvent(event);
        } else if (mainWindow && mainWindow->isAutoRobotMode()) {
            qDebug() << "AutoRobot is being placed at " << pt.x() << " : " << pt.y();
            AutoRobot* object = new AutoRobot(pt.x()-25, pt.y()-25, 0, 25);
            RobotGraphicItem* projection = new RobotGraphicItem(this, nullptr, object);
            object->GetCollider()->SetGraphics(projection);
            projection->setPos(pt.x()-25, pt.y()-25);
            mainWindow->getMap()->AddGameObject(object);
            this->scene->addItem(projection);
            this->update();
            QGraphicsView::mousePressEvent(event);
        } else if (mainWindow && mainWindow->isRCRobotMode() && !_isRCRobotPlaced) {
            _isRCRobotPlaced = true;
            qDebug() << "RCRobot is being placed at " << pt.x() << " : " << pt.y();
            ControlledRobot* object = new ControlledRobot(pt.x()-25, pt.y()-25, 0, 25);
            RobotGraphicItem* projection = new RobotGraphicItem(this, nullptr, object);
            object->GetCollider()->SetGraphics(projection);
            projection->setPos(pt.x()-25, pt.y()-25);
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
     //if (event->delta() > 0) {
     //    scale(1.15, 1.15);
     //} else {
     //    scale(0.85, 0.85);
     //}
     QGraphicsView::wheelEvent(event);
}


void Viewport::keyPressEvent(QKeyEvent *event) {
    auto map = _mainWindow->getMap();
    auto items = map->getGameObjects();
    for (auto& item : items) {
        auto robot = dynamic_cast<IControlledRobot*>(item);
        if (robot) {
            switch (event->key()){
                case Qt::Key_W:
                    qDebug() << "W pressed";
                    robot->SetSpeedDirection(esd_forward);
                    robot->SetRotationDirection(erd_none);
                    break;
                case Qt::Key_S:
                    robot->SetSpeedDirection(esd_none);
                    robot->SetRotationDirection(erd_none);
                    qDebug() << "S pressed";
                    break;
                case Qt::Key_A:
                    if (robot->GetSpeedDirection() != esd_none) {
                        dynamic_cast<IControlledRobot *>(robot)->SetRotationDirection(erd_left);
                    }
                    qDebug() << "A pressed";
                    break;
                case Qt::Key_D:
                    if (robot->GetSpeedDirection() != esd_none) {
                        dynamic_cast<IControlledRobot *>(robot)->SetRotationDirection(erd_right);
                    }
                    qDebug() << "D pressed";
                    break;
                default:
                    QGraphicsView::keyPressEvent(event);
            }
        }
    }
}