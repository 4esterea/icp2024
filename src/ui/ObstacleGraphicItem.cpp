/**
* @file ObstacleGraphicItem.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Implementation of ObstacleGraphicItem
 */


#include "ObstacleGraphicItem.h"


class Obstacle;

ObstacleGraphicItem::ObstacleGraphicItem(Viewport* viewport, QGraphicsItem* parent, Obstacle* obstacle)
    : QGraphicsRectItem(parent), _viewport(viewport), _obstacle(obstacle) {
    setAcceptHoverEvents(true);
    setZValue(10);
    setPen(QPen({Qt::white, 2}));
    setBrush(QColor(255, 255, 255, 32));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    auto collider = _obstacle->GetCollider();
    this->setPos(_obstacle->GetCollider()->GetPosition()->x, _obstacle->GetCollider()->GetPosition()->y);
    this->setRect(0, 0, collider->GetWidth(), collider->GetHeight());
    this->setRotation(collider->GetPosition()->angle);
    this->_obstacle->RecalcColliderPosition();
    std::pair<int, int> mapSize = dynamic_cast<MainWindow*>(_viewport->parentWidget()->parentWidget())->getMap()->getSize();
    if (collider->GetPosition()->x != 0 && collider->GetPosition()->y != 0 && collider->GetPosition()->y != mapSize.second && collider->GetPosition()->x != mapSize.first){
        setAcceptHoverEvents(true);
        setFlag(QGraphicsItem::ItemIsMovable, true);
        setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
        setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
        setFlag(QGraphicsItem::ItemIsFocusable, true);
    } else {
        this->setAcceptedMouseButtons(Qt::NoButton);
    }


}


void ObstacleGraphicItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(_viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled() && mainWindow->isDefault()) {
		setFlag(QGraphicsItem::ItemIsMovable, true);
        setPen(QPen({Qt::red, 2}));
    }
    QGraphicsRectItem::hoverEnterEvent(event);
}

void ObstacleGraphicItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(_viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled() && mainWindow->isDefault()) {
        setFlag(QGraphicsItem::ItemIsMovable, false);
        setPen(QPen({Qt::white, 2}));
    }
    QGraphicsRectItem::hoverLeaveEvent(event);
}


void ObstacleGraphicItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

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
        qDebug() << "Obstacle: The current position is: " << x << " : " << y;
        if(_settings == nullptr){
            _settings = new ObstacleWidget(_viewport, this);
        }

        int viewportWidth = _viewport->width();
        int viewportHeight = _viewport->height();

        bool isCloserToLeft = clickX < viewportWidth / 2;
        bool isCloserToTop = clickY < viewportHeight / 2;

        int newX = isCloserToLeft ? clickX : clickX - _settings->width();
        int newY = isCloserToTop ? clickY : clickY - _settings->height();

        _settings->move(newX, newY);
        dynamic_cast<Viewport*>(_viewport)->hideAllSettings();
        _settings->show();

	} else if(mainWindow && mainWindow->isEditingEnabled()){
        qDebug() << "Deleting the obstacle on the position : " << this->pos().x() << " : " << this->pos().y();
        dynamic_cast<Viewport*>(_viewport)->scene->removeItem(this);
        auto reference = this->_obstacle;
        mainWindow->getMap()->RemoveGameObject(reference);
        delete reference;
    }
    QGraphicsRectItem::mousePressEvent(event);
}

ObstacleWidget *ObstacleGraphicItem::getSettings()
{
    return _settings;
}

void ObstacleGraphicItem::setWidth(int width) {
    qreal centerX = this->boundingRect().width() / 2.0;
    qreal centerY = this->boundingRect().height() / 2.0;
    this->setTransformOriginPoint(centerX, centerY);
    this->_obstacle->GetCollider()->SetWidth(width);
    this->setRect(0, 0, width, this->_obstacle->GetCollider()->GetHeight());
}

void ObstacleGraphicItem::setHeight(int height) {
    qreal centerX = this->boundingRect().width() / 2.0;
    qreal centerY = this->boundingRect().height() / 2.0;
    this->setTransformOriginPoint(centerX, centerY);
    this->_obstacle->GetCollider()->SetHeight(height);
    this->setRect(0, 0, this->_obstacle->GetCollider()->GetWidth(), height);
}


void ObstacleGraphicItem::setRotation(int angle) {
    qreal centerX = this->boundingRect().width() / 2.0;
    qreal centerY = this->boundingRect().height() / 2.0;
    this->setTransformOriginPoint(centerX, centerY);
    QGraphicsRectItem::setRotation(angle);
    this->_obstacle->GetCollider()->GetPosition()->SetPosition(new Position(this->_obstacle->GetPosition()->x, this->_obstacle->GetPosition()->y, angle));
    this->_obstacle->GetPosition()->SetPosition(this->_obstacle->GetPosition()->x, this->_obstacle->GetPosition()->y, angle);
    this->_obstacle->RecalcColliderPosition();
}

QVariant ObstacleGraphicItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (scene()) {
        if (change == ItemPositionHasChanged) {
            dynamic_cast<Viewport*>(_viewport)->hideAllSettings();
            QPointF newPos = value.toPointF();
            this->_obstacle->GetCollider()->GetPosition()->SetPosition(newPos.x(), newPos.y());
            this->_obstacle->GetPosition()->SetPosition(newPos.x(), newPos.y());
        } else if (change == ItemRotationChange) {
            qreal newAngle = value.toReal();
            this->_obstacle->GetCollider()->GetPosition()->SetPosition(this->_obstacle->GetPosition()->x, this->_obstacle->GetPosition()->y, newAngle);
            this->_obstacle->GetPosition()->SetPosition(this->_obstacle->GetPosition()->x, this->_obstacle->GetPosition()->y, newAngle);
        } else if (change == ItemScaleChange) {
            qreal newSize = value.toReal();
            this->_obstacle->GetCollider()->SetWidth(newSize);
            this->_obstacle->GetCollider()->SetHeight(newSize);
        }
        this->_obstacle->RecalcColliderPosition();
    }
    return QGraphicsItem::itemChange(change, value);
}

