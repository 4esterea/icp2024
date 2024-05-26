/**
 * @file IQtRectCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 18.05.2024
 * @brief Definition of Qt Rectangle Collider interface
 */

#ifndef __IQRECTTCOLLIDER_H__
#define __IQRECTTCOLLIDER_H__

#include "IQtCollider.h"

using namespace std;

/**
 * @brief The IQtRectCollider class
 */
class IQtRectCollider : public IQtCollider {
public:
    /**
     * @brief GetGraphics Returns graphics assigned to this object
     * @return Qt graphics
     */
    QGraphicsRectItem * GetGraphics() { return dynamic_cast<QGraphicsRectItem *>(this->_qgraphics); }
    /**
     * @brief GetGraphics Assignes graphics to this object
     * @param qgraphics Qt graphics
     */
    void SetGraphics(QGraphicsRectItem * qgraphics) { this->_qgraphics = qgraphics; };
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
     * @brief GetWidth Returns width of the object
     * @return Width
     */
    virtual double GetWidth() = 0;
    /**
     * @brief SetWidth Sets width of the object
     * @param width New width
     */
    virtual void SetWidth(double width) = 0;
    /**
     * @brief GetHeight Returns height of the object
     * @return Height
     */
    virtual double GetHeight() = 0;
    /**
     * @brief SetHeight Sets new height of the object
     * @param height New height
     */
    virtual void SetHeight(double height) = 0;
    /**
     * @brief GetAngle Returns rotation angle of the object
     * @return Rotation angle
     */
    virtual double GetAngle() = 0;
    /**
     * @brief SetAngle Sets rotation angle of the object
     * @param angle New rotation angle
     */
    virtual void SetAngle(double angle) = 0;
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    virtual bool CheckCollision(ICollider * collider) = 0;
    /**
     * @brief ~IQtRectCollider Abstract destructor
     */
    virtual ~IQtRectCollider() {};
};

#endif
