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

class IObstacle : public IGameObject {
    public:
        double GetWidth() { return this->_width; }
        void SetWidth(double width) { this->_width = width; this->GetCollider()->SetWidth(width); }
        double GetHeight() { return this->_height; }
        void SetHeight(double height) { this->_height = height; this->GetCollider()->SetHeight(height); }
        IQtRectCollider * GetCollider() { return dynamic_cast<IQtRectCollider *>(this->_collider); };
        virtual ~IObstacle() {};

    protected:
        double _width;
        double _height;
};

#endif
