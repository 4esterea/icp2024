/**
 * @file IRectangleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Rectangle Collider interface
 */

#ifndef __IRECTANGLECOLLIDER_H__
#define __IRECTANGLECOLLIDER_H__

#include "ICollider.h"

class IRectangleCollider : public ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual double GetWidth() = 0;
        virtual double GetHeight() = 0;
        virtual IPosition * GetPosition() = 0;
        virtual ~IRectangleCollider() {};
        virtual void SetPosition(IPosition* position) = 0;
        virtual void SetWidth(double width) = 0;
        virtual void SetHeight(double height) = 0;

    protected:
        double _width;
        double _height;
};

#endif
