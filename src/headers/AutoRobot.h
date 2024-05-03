/**
 * @file AutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 03.05.2024
 * @brief Common Auto Robot declaration.
 */

#ifndef __AUTOROBOT_H__
#define __AUTOROBOT_H__

#include "../interfaces/IAutoRobot.h"
#include "../headers/RectangleCollider.h"
#include "../headers/Position.h"
#include "types.h"

class AutoRobot: public IAutoRobot {
    public:
        AutoRobot(double x, double y, double angle, double width, double height);
        void Update();
};

#endif
