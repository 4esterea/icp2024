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

class Position: public IPosition {
    public:
    /**
    * @brief Constructor for the Position class.
    *
    * @param x The initial x-coordinate of the position.
    * @param y The initial y-coordinate of the position.
    * @param angle The initial angle of the position.
    */
    Position(double x, double y, double angle);

    /**
     * @brief Sets the position using an IPosition object.
     *
     * @param position The IPosition object to set the position to.
     */
    void SetPosition(IPosition * position);

    /**
     * @brief Sets the position using x, y coordinates and an angle.
     *
     * @param x The x-coordinate to set the position to.
     * @param y The y-coordinate to set the position to.
     * @param angle The angle to set the position to.
     */
    void SetPosition(double x, double y, double angle);

    /**
     * @brief Sets the position using x, y coordinates.
     *
     * @param x The x-coordinate to set the position to.
     * @param y The y-coordinate to set the position to.
     */
    void SetPosition(double x, double y);
};

#endif
