/**
 * @file QtCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief Implementation of Qt Rect Collider.
 */

#include "../headers/QtRectCollider.h"

QtRectCollider::QtRectCollider(double x, double y, double angle, double width, double height) {
    this->_position = new Position(x, y, angle);
    this->_colliderType = ect_qt_qrect_collider;
    this->_qgraphics = nullptr;
}

bool QtRectCollider::CheckCollision(ICollider * collider) {
    return CollisionChecker::CheckCollision(this, collider);
}

IPosition * QtRectCollider::GetPosition() {
    QRectF r = dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->rect();
    this->_position->x = r.x();
    this->_position->y = r.y();
    this->_position->angle = this->GetAngle();
    return this->_position;
}

void QtRectCollider::SetCoords(double x, double y) {
    dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->setRect(x, y, this->GetWidth(), this->GetHeight());
}

double QtRectCollider::GetWidth() {
    return dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->rect().width();

}

void QtRectCollider::SetWidth(double width) {
    QRectF r = dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->rect();
    dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->setRect(r.x(), r.y(), width, r.height());
}

double QtRectCollider::GetHeight() {
    return dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->rect().height();
}

void QtRectCollider::SetHeight(double height) {
    QRectF r = dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->rect();
    dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->setRect(r.x(), r.y(), r.width(), height);
}

double QtRectCollider::GetAngle() {
    return this->_qgraphics->rotation();
}

void QtRectCollider::SetAngle(double angle) {
    this->_qgraphics->setRotation(angle);
}


