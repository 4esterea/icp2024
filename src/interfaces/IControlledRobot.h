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

/**
 * @brief The IControlledRobot class Controlled robot
 */
class IControlledRobot : public IRobot {
public:
    /**
     * @brief GetSpeedDirection Returns current speed direction
     * @return Speed direction
     */
    virtual SpeedDirection GetSpeedDirection() = 0;
    /**
     * @brief SetSpeedDirection Set new speed direction
     * @param speedDirection New speed direction
     */
    virtual void SetSpeedDirection(SpeedDirection speedDirection) = 0;
    /**
     * @brief GetSpeedDirection Returns current rotation direction
     * @return Rotation direction
     */
    virtual RotationDirection GetRotationDirection() = 0;
    /**
     * @brief SetSpeedDirection Set new rotation direction
     * @param rotationDirection New rotation direction
     */
    virtual void SetRotationDirection(RotationDirection rotationDirection) = 0;
    /**
     * @brief Update Updates gameobject
     */
    virtual void Update() = 0;
    /**
     * @brief ~IGameObject Virtual desctructor
     */
    virtual ~IControlledRobot() {};

protected:
    SpeedDirection _speedDirection;
    RotationDirection _rotationDirection;
    ICollider * _collisionBox; // Body collider ??? TODO
};

#endif
