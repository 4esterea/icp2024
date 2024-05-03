/**
 * @file ControlledRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief Common Auto Robot declaration.
 */

#ifndef __CONTROLLEDROBOT_H__
#define __CONTROLLEDROBOT_H__

#include "../interfaces/IControlledRobot.h"
#include "../headers/RectangleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class ControlledRobot: public IControlledRobot {
public:
    ControlledRobot(double x, double y, double angle, double width, double height);
    void SetSpeedDirection(SpeedDirection speedDirection);
    void SetRotationDirection(RotationDirection rotationDirection);
    void Update();
};

#endif
