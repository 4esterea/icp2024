/**
 * @file AutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief Common Auto Robot declaration.
 */

#ifndef __AUTOROBOT_H__
#define __AUTOROBOT_H__

#include <cmath>
#include <string>
#include "../interfaces/IAutoRobot.h"
#include "../headers/QtCircleCollider.h"
#include "../headers/QtRectCollider.h"
#include "../headers/CircleCollider.h"
#include "../headers/Position.h"
#include "types.h"

/**
 * @brief The AutoRobot class Auto robot
 */
class AutoRobot: public IAutoRobot {
public:
    /**
     * @brief ControlledRobot Constructor of controlled robot
     * @param x X coordinate
     * @param y Y coordinate
     * @param angle Angle of rotation
     * @param radius Radius
     */
    AutoRobot(double x, double y, double angle, double radius);
    /**
     * @brief Get the robot's speed (pure virtual).
     * @return The robot's speed.
     */
    virtual double GetSpeed() = 0;
    /**
     * @brief Set the robot's speed (pure virtual).
     * @param speed The new speed for the robot.
     */
    virtual void SetSpeed(double speed) = 0;
    /**
     * @brief Get the robot's rotation angle (pure virtual).
     * @return The rotation angle in radians.
     */
    virtual double GetRotationAngle() = 0;
    /**
     * @brief Set the robot's rotation angle (pure virtual).
     * @param rotationAngle The new rotation angle in radians.
     */
    void SetRotationAngle(double rotationAngle);
    /**
     * @brief RecalcColliderPosition Recalculates relative collider positions
     */
    void RecalcColliderPosition();
    /**
     * @brief Update Updates gameobject
     */
    void Update();
};

#endif
