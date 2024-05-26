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

/**
 * @brief The IQtCollider class Collider based on Qt graphics item. Uses build-it function to check for collisions
 */
class IQtCollider : public ICollider {
public:
    /**
     * @brief GetGraphics Returns Qt graphics assigned to this object
     * @return Qt graphics
     */
    QGraphicsItem * GetGraphics() { return this->_qgraphics; }
    /**
     * @brief SetGraphics Assignes new qt graphics to the object
     * @param qgraphics New qt graphics
     */
    void SetGraphics(QGraphicsItem * qgraphics) { this->_qgraphics = qgraphics; }
    /**
     * @brief GetPosition Returns position of the object
     * @return Position
     */
    virtual IPosition * GetPosition() = 0;
    /**
     * @brief SetCoords Sets x and y coords of an objects
     * @param x X coord
     * @param y Y coord
     */
    virtual void SetCoords(double x, double y) = 0;
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    virtual bool CheckCollision(ICollider * collider) = 0;
    /**
     * @brief ~IQtCollider Abstract destructor
     */
    virtual ~IQtCollider() {};

protected:
    QGraphicsItem * _qgraphics;
};

#endif
