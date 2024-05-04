#include "RobotGraphicItem.h"

RobotGraphicItem::RobotGraphicItem(Viewport* viewport, QGraphicsItem* parent, IRobot* robot)
    : QGraphicsEllipseItem(parent), _viewport(viewport), _robot(robot), _isRemote(robot->GetObjectType() == eot_controlled_robot) {
    setAcceptHoverEvents(true);
    _direction = new QGraphicsLineItem(this);
    _direction->setLine(25, 25, 25, 0);
    _vision = new QGraphicsRectItem(this);
    _vision->setRect(0, -75, 50, 100);
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
    this->setPos(robot->GetCollider()->GetPosition()->x, _robot->GetCollider()->GetPosition()->y);
    this->setRect(0, 0, collider->GetRadius(), collider->GetRadius()); // TODO change to circle idk
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

        QPointF clickPosition = event->scenePos();
        qreal clickX = clickPosition.x();
        qreal clickY = clickPosition.y();
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
        // auto reference = this->_robot;
        // mainWindow->getMap()->RemoveGameObject(reference);
        // delete reference;
        // delete this;
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
    }
    return QGraphicsItem::itemChange(change, value);
}

void RobotGraphicItem::setRotation(int angle) {
    setTransformOriginPoint(25, 25);
    QGraphicsEllipseItem::setRotation(angle);
    // _direction->setRotation(angle);
    // _autoRobot->GetCollider()->set...; TODO
}
