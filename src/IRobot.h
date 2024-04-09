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

using namespace std;

class IRobot : public IGameObject {
    public:
        virtual void Update() = 0;
        virtual ~IRobot() = 0;

    private:
        float _speed; // Constant through run
        float _rotationAngle; // Constant through run
};

#endif