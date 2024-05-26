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
#include "../headers/QtCircleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class ControlledRobot: public IControlledRobot {
public:
    /**
     * @brief ControlledRobot Constructor of controlled robot
     * @param x X coordinate
     * @param y Y coordinate
     * @param angle Angle of rotation
     * @param radius Radius
     */
    ControlledRobot(double x, double y, double angle, double radius);
    /**
     * @brief GetSpeed Returns speed of the robot
     * @return Speed
     */
    double GetSpeed();
    /**
     * @brief SetSpeed Sets new speed
     * @param speed New speed
     */
    void SetSpeed(double speed);
    /**
     * @brief GetRotationAngle Returns current rotation angle
     * @return Rotation angle
     */
    double GetRotationAngle();
    /**
     * @brief SetRotationAngle Sets new rotation angle
     * @param rotationAngle New rotation angle
     */
    void SetRotationAngle(double rotationAngle);
    /**
     * @brief GetSpeedDirection Returns current speed direction
     * @return Speed direction
     */
    SpeedDirection GetSpeedDirection();
    /**
     * @brief SetSpeedDirection Set new speed direction
     * @param speedDirection New speed direction
     */
    void SetSpeedDirection(SpeedDirection speedDirection);
    /**
     * @brief GetSpeedDirection Returns current rotation direction
     * @return Rotation direction
     */
    RotationDirection GetRotationDirection();
    /**
     * @brief SetSpeedDirection Set new rotation direction
     * @param rotationDirection New rotation direction
     */
    void SetRotationDirection(RotationDirection rotationDirection);
    /**
     * @brief Update Updates gameobject
     */
    void Update();
    /**
     * @brief RecalcColliderPosition Recalculates relative collider positions
     */
    void RecalcColliderPosition();
};

#endif
