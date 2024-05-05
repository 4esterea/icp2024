/**
 * @file ControlledRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
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
        ControlledRobot(double x, double y, double angle, double radius);
        double GetSpeed();
        void SetSpeed(double speed);
        double GetRotationAngle();
        void SetRotationAngle(double rotationAngle);
        SpeedDirection GetSpeedDirection();
        void SetSpeedDirection(SpeedDirection speedDirection);
        RotationDirection GetRotationDirection();
        void SetRotationDirection(RotationDirection rotationDirection);
        void RecalcColliderPosition();
        void Update();
};

#endif
