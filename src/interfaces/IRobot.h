/**
 * @file IRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Robot interface
 */

#ifndef __IROBOT_H__
#define __IROBOT_H__

#include "IGameObject.h"

class IRobot : public IGameObject {
    public:
        virtual void Update() = 0;
        virtual ~IRobot() {};

    private:
        double _speed; // Constant through run
        double _rotationAngle; // Constant through run
};

#endif
