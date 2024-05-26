/**
 * @file QtCircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of Qt Circle Collider.
 */

#ifndef __QTCIRCLECOLLIDER_H__
#define __QTCIRCLECOLLIDER_H__

#include <cmath>
#include "../interfaces/IQtCircleCollider.h"
#include "Position.h"
#include "CollisionChecker.h"

/**
 * @brief The QtCircleCollider class Circle collider based on Qt graphics
 */
class QtCircleCollider : public IQtCircleCollider {
public:
    /**
     * @brief QtCircleCollider Constructor of qt circle collider
     * @param x X coordinate
     * @param y Y coordinate
     * @param radius Radius of circle
     */
    QtCircleCollider(double x, double y, double radius);
    /**
     * @brief GetPosition Returns position of the object
     * @return Position
     */
    IPosition * GetPosition();
    /**
     * @brief SetCoords Sets x and y coords of an objects
     * @param x X coord
     * @param y Y coord
     */
    void SetCoords(double x, double y);
    /**
     * @brief GetRadius Returns radius of the collider
     * @return Ragius
     */
    double GetRadius();
    /**
     * @brief SetRadius Assignes new radius to the collider
     * @param radius New radius
     */
    void SetRadius(double radius);
    /**
     * @brief CheckCollision Checks collisions with another collider
     * @param collider Collider
     * @return True if collides
     */
    bool CheckCollision(ICollider * collider);
    ~QtCircleCollider() {};
};

#endif
