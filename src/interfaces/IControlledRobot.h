/**
 * @file IControlledRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Controlled Robot doubleerface
 */

#ifndef __ICONTROLLEDROBOT_H__
#define __ICONTROLLEDROBOT_H__

#include <utility>

#include "IRobot.h"

using namespace std;

class IControlledRobot : public IRobot {
    public:
        virtual SpeedDirection GetSpeedDirection() = 0;
        virtual void SetSpeedDirection(SpeedDirection speedDirection) = 0;
        virtual RotationDirection GetRotationDirection() = 0;
        virtual void SetRotationDirection(RotationDirection rotationDirection) = 0;
        virtual void Update() = 0;
        virtual ~IControlledRobot() {};

    protected:
        SpeedDirection _speedDirection;
        RotationDirection _rotationDirection;
        ICollider * _collisionBox; // Body collider ??? TODO
};

#endif
