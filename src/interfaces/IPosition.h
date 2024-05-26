/**
 * @file IPosition.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Position interface
 */

#ifndef __IPOSITION_H__
#define __IPOSITION_H__

/**
* @brief The IPosition class Definition of object's position
*/
class IPosition {
public:
    /**
     * @brief x X coordinate
     */
    double x;
    /**
     * @brief y Y coordinate
     */
    double y;
    /**
     * @brief angle Angle of rotation
     */
    double angle;

    /**
     * @brief SetPosition Sets new position
     * @param position New position
     */
    virtual void SetPosition(IPosition * position) = 0;
    /**
     * @brief SetPosition Sets new position
     * @param x New x coord
     * @param y New y coord
     * @param angle New angle
     */
    virtual void SetPosition(double x, double y, double angle) = 0;
    /**
     * @brief SetPosition Sets new position
     * @param x New x coord
     * @param y New y coord
     */
    virtual void SetPosition(double x, double y) = 0;
    /**
     * @brief SetPosition Sets new position
     * @param angle New angle
     */
    virtual void SetPosition(double angle) = 0;
    /**
     * @brief ~IPosition Abstract destructor
     */
    virtual ~IPosition() {};
};

#endif
