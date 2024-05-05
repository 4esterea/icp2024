/**
* @file RobotGraphicItem.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Implementation of RobotGraphicItem
 */



#include "RobotGraphicItem.h"

RobotGraphicItem::RobotGraphicItem(Viewport* viewport, QGraphicsItem* parent, IRobot* robot)
    : QGraphicsEllipseItem(parent), _viewport(viewport), _robot(robot), _isRemote(robot->GetObjectType() == eot_controlled_robot) {
    setAcceptHoverEvents(true);
    _direction = new QGraphicsLineItem(this);
    _direction->setLine(25, 25, 50, 25);
    _vision = new QGraphicsRectItem(this);
    //_vision->setRect(25, 0, _robot->GetVision().rect().width(), 50);
    _vision->setRect(25, 0, 100, 50); // TODO: ^use the upper line after the robot is implemented
    _vision->setPen(QPen(QColor(255, 0, 0, 128), 2));
    _vision->setFlag(QGraphicsItem::ItemStacksBehindParent, true);
    if (_isRemote) {
        _direction->setPen(QPen({Qt::yellow, 2}));
        setPen(QPen({Qt::yellow, 2}));
    } else {
        _direction->setPen(QPen({Qt::white, 2}));
        setPen(QPen({Qt::white, 2}));
    }
    setBrush(QBrush(Qt::black));
    setRect(0, 0, 50, 50);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    auto collider = dynamic_cast<CircleCollider *>(_robot->GetCollider());
    this->setPos(_robot->GetCollider()->GetPosition()->x, _robot->GetCollider()->GetPosition()->y);
    this->setRect(0, 0, collider->GetRadius() * 2, collider->GetRadius() * 2);
    this->setRotation(collider->GetPosition()->angle);
}

void RobotGraphicItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(_viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled() && mainWindow->isDefault()) {
        setFlag(QGraphicsItem::ItemIsMovable, true);
        setPen(QPen({Qt::red, 2}));
        _direction->setPen(QPen({Qt::red, 2}));
    }
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void RobotGraphicItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(_viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled() && mainWindow->isDefault()) {
        setFlag(QGraphicsItem::ItemIsMovable, false);
        setPen((_isRemote ? QPen({Qt::yellow, 2}) : QPen({Qt::white, 2})) );
        _direction->setPen((_isRemote ? QPen({Qt::yellow, 2}) : QPen({Qt::white, 2})) );
    }
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

void RobotGraphicItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(_viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled() && event->button() == Qt::LeftButton){
        QPointF position = this->pos();
        qreal x = position.x();
        qreal y = position.y();

        QPointF sceneClickPosition = event->scenePos();
        QGraphicsView* graphicsView = qobject_cast<QGraphicsView*>(_viewport);
        QPoint viewportClickPosition;
        if (graphicsView) {
            viewportClickPosition = graphicsView->mapFromScene(sceneClickPosition);
        }
        qreal clickX = viewportClickPosition.x();
        qreal clickY = viewportClickPosition.y();

        qDebug() << (_isRemote ? "RC Robot" : "Auto Robot") << ": The current position is: " << x << " : " << y;
        if(_settings == nullptr){
                _settings = new RobotWidget(_viewport, this, _isRemote);
        }
        int viewportWidth = _viewport->width();
        int viewportHeight = _viewport->height();
        bool isCloserToLeft = x < viewportWidth / 2;
        bool isCloserToTop = y < viewportHeight / 2;

        int newX = isCloserToLeft ? clickX : clickX - _settings->width();
        int newY = isCloserToTop ? clickY : clickY - _settings->height();

        _settings->move(newX, newY);
        dynamic_cast<Viewport*>(_viewport)->hideAllSettings();
        _settings->show();
    } else if (mainWindow && mainWindow->isEditingEnabled() && event->button() == Qt::RightButton){
        qDebug() << "Deleting the robot on the position : " << this->pos().x() << " : " << this->pos().y();
        dynamic_cast<Viewport*>(_viewport)->scene->removeItem(this);
        auto reference = this->_robot;
        mainWindow->getMap()->RemoveGameObject(reference);
        delete reference;
    }
    QGraphicsEllipseItem::mouseDoubleClickEvent(event);
}

QWidget* RobotGraphicItem::getSettings() {
    return _settings;
}

QVariant RobotGraphicItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange) {
        Viewport* viewport = dynamic_cast<Viewport*>(_viewport);
        if (viewport) {
            viewport->hideAllSettings();
        }
        QPointF newPos = value.toPointF();
        _robot->GetCollider()->GetPosition()->SetPosition(newPos.x(), newPos.y());
        _robot->GetPosition()->SetPosition(newPos.x(), newPos.y());
    }
    return QGraphicsItem::itemChange(change, value);
}

void RobotGraphicItem::setRotation(int angle) {
    setTransformOriginPoint(25, 25);
    QGraphicsEllipseItem::setRotation(angle);
    _robot->GetPosition()->angle = angle;
    _robot->GetCollider()->GetPosition()->angle = angle;
}

void RobotGraphicItem::Update() {
    auto position = dynamic_cast<Position *>(_robot->GetPosition());
	setPos(position->x, position->y);
    setRotation(position->angle);
}

IRobot* RobotGraphicItem::getGameObject() {
    return _robot;
}

QGraphicsRectItem* RobotGraphicItem::getVision() {
    return _vision;
}

void RobotGraphicItem::keyPressEvent(QKeyEvent *event) {
    if (_isRemote) {
        switch (event->key()){
           case Qt::Key_W:
               qDebug() << "W pressed";
               break;
           case Qt::Key_S:
               qDebug() << "S pressed";
               break;
           case Qt::Key_A:
               qDebug() << "A pressed";
               break;
           case Qt::Key_D:
               qDebug() << "D pressed";
               break;
           default:
               QGraphicsEllipseItem::keyPressEvent(event);
        }
    }
}
