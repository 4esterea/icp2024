/**
 * @file IControlledRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Controlled Robot interface
 */

#ifndef __ICONTROLLEDROBOT_H__
#define __ICONTROLLEDROBOT_H__

#include <utility>

#include "IRobot.h"

using namespace std;

class IControlledRobot : public IRobot {
    public:
    /**
     * @brief Gets the speed direction of the controlled robot.
     *
     * @return The speed direction of the controlled robot.
     */
    virtual SpeedDirection GetSpeedDirection() = 0;

    /**
     * @brief Sets the speed direction of the controlled robot.
     *
     * @param speedDirection The speed direction to set the controlled robot to.
     */
    virtual void SetSpeedDirection(SpeedDirection speedDirection) = 0;

    /**
     * @brief Gets the rotation direction of the controlled robot.
     *
     * @return The rotation direction of the controlled robot.
     */
    virtual RotationDirection GetRotationDirection() = 0;

    /**
     * @brief Sets the rotation direction of the controlled robot.
     *
     * @param rotationDirection The rotation direction to set the controlled robot to.
     */
    virtual void SetRotationDirection(RotationDirection rotationDirection) = 0;

    /**
     * @brief Updates the state of the controlled robot.
     */
    virtual void Update() = 0;

    /**
     * @brief Virtual destructor for the IControlledRobot interface.
     */
    virtual ~IControlledRobot() {};

    protected:
        SpeedDirection _speedDirection;
        RotationDirection _rotationDirection;
        ICollider * _collisionBox; // Body collider ??? TODO
};

#endif
