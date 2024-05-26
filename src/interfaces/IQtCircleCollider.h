/**
 * @file IQtCircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 18.05.2024
 * @brief Definition of Qt Circle Collider interface
 */

#ifndef __IQTCIRCLECOLLIDER_H__
#define __IQTCIRCLECOLLIDER_H__

#include "IQtCollider.h"

using namespace std;

/**
 * @brief The IQtCircleCollider class Circle collider based on Qt graphics item
 */
class IQtCircleCollider : public IQtCollider {
public:
    /**
     * @brief GetGraphics Returns Qt graphics assigned to this object
     * @return Qt graphics
     */
    QGraphicsEllipseItem * GetGraphics() { return dynamic_cast<QGraphicsEllipseItem *>(this->_qgraphics); }
    /**
     * @brief SetGraphics Assignes new qt graphics to the object
     * @param qgraphics New qt graphics
     */
    void SetGraphics(QGraphicsEllipseItem * qgraphics) { this->_qgraphics = qgraphics; }
    /**
     * @brief GetRadius Returns radius of the collider
     * @return Ragius
     */
    virtual double GetRadius() = 0;
    /**
     * @brief SetRadius Assignes new radius to the collider
     * @param radius New radius
     */
    virtual void SetRadius(double radius) = 0;
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    virtual bool CheckCollision(ICollider * collider) = 0;
    /**
     * @brief ~IQtCircleCollider Abstract destructor
     */
    virtual ~IQtCircleCollider() {};

protected:
    double _radius;
};

#endif
