#include "ObstacleGraphicItem.h"
#include "Viewport.h"
#include <QGraphicsRectItem>
#include <QPen>
#include <QDebug>
#include <QWidget>
#include <QGraphicsSceneHoverEvent>
#include <QPointF>
#include "ObstacleWidget.h"
#include "../mainwindow.h"

class Obstacle;

ObstacleGraphicItem::ObstacleGraphicItem(Viewport* viewport, QGraphicsItem* parent, Obstacle* obstacle)
    : QGraphicsRectItem(parent), viewport(viewport), obstacle(obstacle) {
    setAcceptHoverEvents(true);
    setPen(QPen({Qt::white, 2}));
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    auto collider = obstacle->GetCollider();
    this->setPos(obstacle->GetCollider()->GetPosition()->x, obstacle->GetCollider()->GetPosition()->y);
    this->setRect(0, 0, collider->GetWidth(), collider->GetHeight());
    this->setRotation(collider->GetPosition()->angle);

}


void ObstacleGraphicItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled()) {
		setFlag(QGraphicsItem::ItemIsMovable, true);
        setPen(QPen({Qt::red, 2}));
        QGraphicsRectItem::hoverEnterEvent(event);
    } else {
        setFlag(QGraphicsItem::ItemIsMovable, false);
		QGraphicsRectItem::hoverEnterEvent(event);
    }
}

void ObstacleGraphicItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled()) {
		setFlag(QGraphicsItem::ItemIsMovable, true);
        setPen(QPen({Qt::white, 2}));
        QGraphicsRectItem::hoverLeaveEvent(event);
    } else {
        setFlag(QGraphicsItem::ItemIsMovable, false);
		QGraphicsRectItem::hoverEnterEvent(event);
    }
}


void ObstacleGraphicItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

	MainWindow* mainWindow = dynamic_cast<MainWindow*>(viewport->parentWidget()->parentWidget());
    if (mainWindow && mainWindow->isEditingEnabled() && event->button() == Qt::LeftButton){
        QPointF position = this->pos();
        qreal x = position.x();
        qreal y = position.y();
        qDebug() << "Obstacle: The current position is: " << x << " : " << y;
        if(settings == nullptr){
            settings = new ObstacleWidget(viewport, this);
        }

        int viewportWidth = viewport->width();
        int viewportHeight = viewport->height();

        bool isCloserToLeft = x < viewportWidth / 2;
        bool isCloserToTop = y < viewportHeight / 2;

        qreal newX = isCloserToLeft ? x + settings->width()/2 : x - settings->width()/2;
        qreal newY = isCloserToTop ? y + settings->height()/2 : y - settings->height();

        settings->move(newX, newY);
        dynamic_cast<Viewport*>(viewport)->hideAllSettings();
        settings->show();

        QGraphicsRectItem::mousePressEvent(event);
	} else if(mainWindow && mainWindow->isEditingEnabled()){
        qDebug() << "Deleting the obstacle on the position : " << this->pos().x() << " : " << this->pos().y();
        dynamic_cast<Viewport*>(viewport)->scene->removeItem(this);
        auto reference = this->obstacle;
        mainWindow->getMap()->RemoveGameObject(reference);
        delete reference;
    }
}

ObstacleWidget *ObstacleGraphicItem::getSettings()
{
    return this->settings;
}

void ObstacleGraphicItem::setWidth(int width) {
    qreal centerX = this->boundingRect().width() / 2.0;
    qreal centerY = this->boundingRect().height() / 2.0;
    this->setTransformOriginPoint(centerX, centerY);
    this->obstacle->GetCollider()->SetWidth(width);
    this->setRect(0, 0, width, this->obstacle->GetCollider()->GetHeight());
}

void ObstacleGraphicItem::setHeight(int height) {
    qreal centerX = this->boundingRect().width() / 2.0;
    qreal centerY = this->boundingRect().height() / 2.0;
    this->setTransformOriginPoint(centerX, centerY);
    this->obstacle->GetCollider()->SetHeight(height);
    this->setRect(0, 0, this->obstacle->GetCollider()->GetWidth(), height);
}


void ObstacleGraphicItem::setRotation(int angle) {
    qreal centerX = this->boundingRect().width() / 2.0;
    qreal centerY = this->boundingRect().height() / 2.0;
    this->setTransformOriginPoint(centerX, centerY);
    QGraphicsRectItem::setRotation(angle);
    this->obstacle->GetCollider()->SetPosition(new Position(this->obstacle->GetPosition()->x, this->obstacle->GetPosition()->y, angle));
}

QVariant ObstacleGraphicItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (scene()) {
        if (change == ItemPositionHasChanged) {
            QPointF newPos = value.toPointF();
            this->obstacle->GetCollider()->SetPosition(new Position(newPos.x(), newPos.y(), this->obstacle->GetPosition()->angle));
            this->obstacle->UpdateCoords(newPos.x(), newPos.y());
        } else if (change == ItemRotationChange) {
            qreal newAngle = value.toReal();
            this->obstacle->GetCollider()->SetPosition(new Position(this->obstacle->GetPosition()->x, this->obstacle->GetPosition()->y, newAngle));
        } else if (change == ItemScaleChange) {
            qreal newSize = value.toReal();
            this->obstacle->GetCollider()->SetWidth(newSize);
            this->obstacle->GetCollider()->SetHeight(newSize);
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
