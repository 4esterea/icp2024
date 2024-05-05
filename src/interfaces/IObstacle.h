/**
 * @file IObstacle.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Obstacle doubleerface
 */

#ifndef __IOBSTACLE_H__
#define __IOBSTACLE_H__

#include "IGameObject.h"
#include "../headers/RectangleCollider.h"

using namespace std;

class IObstacle : public IGameObject {
    public:
        IRectangleCollider * GetCollider() { return dynamic_cast<IRectangleCollider *>(this->_collider); };
        virtual ~IObstacle() {};
};

#endif
