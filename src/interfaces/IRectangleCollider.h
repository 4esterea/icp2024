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

class IRectangleCollider : public ICollider {
    public:
    /**
     * @brief Gets the width of the rectangle collider.
     *
     * @return The width of the rectangle collider.
     */
    virtual double GetWidth() = 0;

    /**
     * @brief Sets the width of the rectangle collider.
     *
     * @param width The width to set the rectangle collider to.
     */
    virtual void SetWidth(double width) = 0;

    /**
     * @brief Gets the height of the rectangle collider.
     *
     * @return The height of the rectangle collider.
     */
    virtual double GetHeight() = 0;

    /**
     * @brief Sets the height of the rectangle collider.
     *
     * @param height The height to set the rectangle collider to.
     */
    virtual void SetHeight(double height) = 0;

    /**
     * @brief Virtual destructor for the IRectangleCollider interface.
     */
    virtual ~IRectangleCollider() {};

    protected:
        double _width;
        double _height;
};

#endif
