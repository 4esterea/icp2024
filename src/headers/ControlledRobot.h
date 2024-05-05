/**
 * @file ControlledRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 03.05.2024
 * @brief Common Controlled Robot declaration.
 */

#ifndef __CONTROLLEDROBOT_H__
#define __CONTROLLEDROBOT_H__

#include "../interfaces/IControlledRobot.h"
#include "../headers/CircleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class ControlledRobot: public IControlledRobot {
    public:
    /**
    * @brief Constructor for the ControlledRobot class.
    *
    * @param x The initial x-coordinate of the robot.
    * @param y The initial y-coordinate of the robot.
    * @param angle The initial angle of the robot.
    * @param radius The radius of the robot.
    */
    ControlledRobot(double x, double y, double angle, double radius);

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
     * @brief Gets the speed direction of the robot.
     *
     * @return The speed direction of the robot.
     */
    SpeedDirection GetSpeedDirection();

    /**
     * @brief Sets the speed direction of the robot.
     *
     * @param speedDirection The speed direction to set the robot to.
     */
    void SetSpeedDirection(SpeedDirection speedDirection);

    /**
     * @brief Gets the rotation direction of the robot.
     *
     * @return The rotation direction of the robot.
     */
    RotationDirection GetRotationDirection();

    /**
     * @brief Sets the rotation direction of the robot.
     *
     * @param rotationDirection The rotation direction to set the robot to.
     */
    void SetRotationDirection(RotationDirection rotationDirection);

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
