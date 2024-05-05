    /**
 * @file IPosition.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Position interface
 */

#ifndef __IPOSITION_H__
#define __IPOSITION_H__

class IPosition {
public:
    /**
     * @brief The x-coordinate of the position.
     */
    double x;

    /**
     * @brief The y-coordinate of the position.
     */
    double y;

    /**
     * @brief The angle of the position.
     */
    double angle;

    /**
     * @brief Sets the position using another position object.
     *
     * @param position A pointer to the position object to copy from.
     */
    virtual void SetPosition(IPosition * position) = 0;

    /**
     * @brief Sets the position using x, y coordinates and an angle.
     *
     * @param x The x-coordinate to set.
     * @param y The y-coordinate to set.
     * @param angle The angle to set.
     */
    virtual void SetPosition(double x, double y, double angle) = 0;

    /**
     * @brief Sets the position using x, y coordinates. The angle is not changed.
     *
     * @param x The x-coordinate to set.
     * @param y The y-coordinate to set.
     */
    virtual void SetPosition(double x, double y) = 0;

    /**
     * @brief Virtual destructor for the IPosition interface.
     */
    virtual ~IPosition();
};

#endif
