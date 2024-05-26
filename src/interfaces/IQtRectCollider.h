/**
 * @file IQtCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 18.05.2024
 * @brief Definition of Qt Collider interface
 */

#ifndef __IQRECTTCOLLIDER_H__
#define __IQRECTTCOLLIDER_H__

#include "IQtCollider.h"

using namespace std;

class IQtRectCollider : public IQtCollider {
public:
    QGraphicsRectItem * GetGraphics() { return dynamic_cast<QGraphicsRectItem *>(this->_qgraphics); }
    void SetGraphics(QGraphicsRectItem * qgraphics) { this->_qgraphics = qgraphics; };
    virtual IPosition * GetPosition() = 0;
    virtual void SetCoords(double x, double y) = 0;
    virtual double GetWidth() = 0;
    virtual void SetWidth(double width) = 0;
    virtual double GetHeight() = 0;
    virtual void SetHeight(double height) = 0;
    virtual double GetAngle() = 0;
    virtual void SetAngle(double angle) = 0;
    virtual bool CheckCollision(ICollider * collider) = 0;
    virtual ~IQtRectCollider() {};
};

#endif
