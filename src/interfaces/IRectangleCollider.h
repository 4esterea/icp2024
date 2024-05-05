/**
 * @file IRectangleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Rectangle Collider doubleerface
 */

#ifndef __IRECTANGLECOLLIDER_H__
#define __IRECTANGLECOLLIDER_H__

#include "ICollider.h"

class IRectangleCollider : public ICollider {
    public:
        virtual double GetWidth() = 0;
        virtual void SetWidth(double width) = 0;
        virtual double GetHeight() = 0;
        virtual void SetHeight(double height) = 0;
        virtual ~IRectangleCollider() {};

    protected:
        double _width;
        double _height;
};

#endif
