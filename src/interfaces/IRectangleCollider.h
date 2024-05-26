/**
 * @file IRectangleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Rectangle Collider interface
 */

#ifndef __IRECTANGLECOLLIDER_H__
#define __IRECTANGLECOLLIDER_H__

#include "ICollider.h"

/**
 * @brief Base class for rectangle colliders.

 */
class IRectangleCollider : public ICollider {
public:
    /**
     * @brief Get the width of the collider.
     * @return The width of the collider.
     */
    virtual double GetWidth() = 0;

    /**
     * @brief Set the width of the collider.
     * @param width The new width for the collider.
     */
    virtual void SetWidth(double width) = 0;

    /**
     * @brief Get the height of the collider.
     * @return The height of the collider.
     */
    virtual double GetHeight() = 0;

    /**
     * @brief Set the height of the collider.
     * @param height The new height for the collider.
     */
    virtual void SetHeight(double height) = 0;

    /**
     * @brief Virtual destructor for IRectangleCollider.
     */
    virtual ~IRectangleCollider() {};

protected:
    double _width;
    double _height;
};

#endif
