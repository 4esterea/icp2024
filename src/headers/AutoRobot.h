/**
 * @file AutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief Common Auto Robot declaration.
 */

#ifndef __AUTOROBOT_H__
#define __AUTOROBOT_H__

#include <string>
#include "../interfaces/IAutoRobot.h"
#include "../headers/RectangleCollider.h"
#include "../headers/CircleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class AutoRobot: public IAutoRobot {
    public:
        AutoRobot(int x, int y, int angle, int radius);
        int GetSpeed();
        void SetSpeed(int speed);
        int GetRotationAngle();
        void SetRotationAngle(int rotationAngle);
        void Update();
};

#endif
