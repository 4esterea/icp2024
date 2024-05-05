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
#include "../headers/RectangleCollider.h"
#include "../headers/CircleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class AutoRobot: public IAutoRobot {
    public:
    /**
    * @brief Constructor for the AutoRobot class.
    *
    * @param x The initial x-coordinate of the robot.
    * @param y The initial y-coordinate of the robot.
    * @param angle The initial angle of the robot.
    * @param radius The radius of the robot.
    */
    AutoRobot(double x, double y, double angle, double radius);

    /**
     * @brief Gets the speed of the robot.
     *
     * @return The speed of the robot.
     */
    double GetSpeed();

    /**
     * @brief Sets the speed of the robot.
     *
     * @param speed The speed to set the robot to.
     */
    void SetSpeed(double speed);

    /**
     * @brief Gets the rotation angle of the robot.
     *
     * @return The rotation angle of the robot.
     */
    double GetRotationAngle();

    /**
     * @brief Sets the rotation angle of the robot.
     *
     * @param rotationAngle The rotation angle to set the robot to.
     */
    void SetRotationAngle(double rotationAngle);

    /**
     * @brief Recalculates the position of the robot's collider.
     */
    void RecalcColliderPosition();

    /**
     * @brief Updates the state of the robot.
     */
    void Update();
};

#endif
