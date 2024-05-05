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
        AutoRobot(double x, double y, double angle, double radius);
        double GetSpeed();
        void SetSpeed(double speed);
        double GetRotationAngle();
        void SetRotationAngle(double rotationAngle);
        void RecalcColliderPosition();
        void Update();
};

#endif
