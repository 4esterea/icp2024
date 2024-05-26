/**
 * @file QtCollider.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief Implementation of Qt Rect Collider.
 */

#include "../headers/QtCircleCollider.h"

QtCircleCollider::QtCircleCollider(double x, double y, double radius) {
    this->_position = new Position(x, y, 0);
    this->_colliderType = ect_qt_qcirc_collider;
    this->_radius = radius;
    this->_qgraphics = nullptr;
}

IPosition * QtCircleCollider::GetPosition() {
    QRectF r = this->GetGraphics()->rect();
    this->_position->x = r.x();
    this->_position->y = r.y();
    this->_position->angle = 0;
    return this->_position;
}

void QtCircleCollider::SetCoords(double x, double y) {
    this->GetGraphics()->setRect(x, y, this->GetRadius(), this->GetRadius());
}

double QtCircleCollider::GetRadius() {
    return this->_radius;
}

void QtCircleCollider::SetRadius(double radius) {
    this->_radius = radius;
}

// double QtCircleCollider::GetRadius() {
//     return dynamic_cast<QGraphicsEllipseItem *>(this->_qgraphics)->rect().width() / 2;
// }

// void QtCircleCollider::SetRadius(double radius) {
//     QRectF r = dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->rect();
//     dynamic_cast<QGraphicsRectItem *>(this->_qgraphics)->setRect(r.x(), r.y(), radius, radius);
// }

bool QtCircleCollider::CheckCollision(ICollider * collider) {
    return CollisionChecker::CheckCollision(this, collider);
}
