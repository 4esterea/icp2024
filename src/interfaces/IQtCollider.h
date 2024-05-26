/**
 * @file IQtCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 18.05.2024
 * @brief Definition of Qt Collider interface
 */

#ifndef __IQTCOLLIDER_H__
#define __IQTCOLLIDER_H__

#include "ICollider.h"

using namespace std;

class IQtCollider : public ICollider {
    public:
        QGraphicsItem * GetGraphics() { return this->_qgraphics; }
        void SetGraphics(QGraphicsItem * qgraphics) { this->_qgraphics = qgraphics; }
        virtual IPosition * GetPosition() = 0;
        virtual void SetCoords(double x, double y) = 0;
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~IQtCollider() {};

    protected:
        QGraphicsItem * _qgraphics;
};

#endif
