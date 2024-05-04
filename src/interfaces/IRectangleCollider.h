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
        virtual int GetWidth() = 0;
        virtual void SetWidth(int width) = 0;
        virtual int GetHeight() = 0;
        virtual void SetHeight(int height) = 0;
        virtual ~IRectangleCollider() {};

    protected:
        int _width;
        int _height;
};

#endif
