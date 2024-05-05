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
#include "../headers/RectangleCollider.h"

using namespace std;

class IObstacle : public IGameObject {
    public:
    /**
     * @brief Gets the rectangle collider of the obstacle.
     *
     * @return A pointer to the rectangle collider of the obstacle.
     */
    IRectangleCollider * GetCollider();

    /**
     * @brief Virtual destructor for the IObstacle interface.
     */
    virtual ~IObstacle();
};

#endif
