/**
 * @file IObstacle.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Obstacle interface
 */

#ifndef __IOBSTACLE_H__
#define __IOBSTACLE_H__

#include "IGameObject.h"
#include "IQtRectCollider.h"

using namespace std;

/**
 * @brief The IObstacle class Obstacle
 */
class IObstacle : public IGameObject {
public:
    /**
     * @brief GetWidth Returns width of the object
     * @return Width
     */
    double GetWidth() { return this->_width; }
    /**
     * @brief SetWidth Sets width of the object
     * @param width New width
     */
    void SetWidth(double width) { this->_width = width; this->GetCollider()->SetWidth(width); }
    /**
     * @brief GetHeight Returns height of the object
     * @return Height
     */
    double GetHeight() { return this->_height; }
    /**
     * @brief SetHeight Sets new height of the object
     * @param height New height
     */
    void SetHeight(double height) { this->_height = height; this->GetCollider()->SetHeight(height); }
    /**
     * @brief GetCollider Returns collider assigned to the object
     * @return Collider
     */
    IQtRectCollider * GetCollider() { return dynamic_cast<IQtRectCollider *>(this->_collider); };
    /**
     * @brief ~IObstacle Virtual destructor
     */
    virtual ~IObstacle() {};

protected:
    double _width;
    double _height;
};

#endif
