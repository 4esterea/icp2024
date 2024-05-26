/**
 * @file IQtCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 18.05.2024
 * @brief Definition of Qt Collider interface
 */

#ifndef __IQTCIRCLECOLLIDER_H__
#define __IQTCIRCLECOLLIDER_H__

#include "IQtCollider.h"

using namespace std;

class IQtCircleCollider : public IQtCollider {
    public:
        QGraphicsEllipseItem * GetGraphics() { return dynamic_cast<QGraphicsEllipseItem *>(this->_qgraphics); }
        void SetGraphics(QGraphicsEllipseItem * qgraphics) { this->_qgraphics = qgraphics; }
        virtual double GetRadius() = 0;
        virtual void SetRadius(double radius) = 0;
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~IQtCircleCollider() {};

    protected:
        double _radius;
};

#endif
