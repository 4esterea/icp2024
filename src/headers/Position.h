/**
 * @file Position.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of GameObject's position.
 */

#ifndef __POSITION_H__
#define __POSITION_H__

#include "../interfaces/IPosition.h"

/**
 * @brief The Position class Basic position
 */
class Position: public IPosition {
public:
    /**
     * @brief Position Constructor of position
     * @param x X coordinate
     * @param y Y coordinate
     * @param angle Angle of rotation
     */
    Position(double x, double y, double angle);
    /**
     * @brief SetPosition Sets new position
     * @param position New position
     */
    void SetPosition(IPosition * position);
    /**
     * @brief SetPosition Sets new position
     * @param x New x coord
     * @param y New y coord
     * @param angle New angle
     */
    void SetPosition(double x, double y, double angle);
    /**
     * @brief SetPosition Sets new position
     * @param x New x coord
     * @param y New y coord
     */
    void SetPosition(double x, double y);
    /**
     * @brief SetPosition Sets new position
     * @param angle New angle
     */
    void SetPosition(double angle);
};

#endif
