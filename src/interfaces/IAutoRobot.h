/**
 * @file IAutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Auto Robot doubleerface
 */

#ifndef __IAUTOROBOT_H__
#define __IAUTOROBOT_H__

#include <utility>

#include "IRobot.h"

using namespace std;

class IAutoRobot : public IRobot {
    public:
        ICollider * GetVision() { return this->_vision; }
        void SetVision(ICollider * vision) { this->_vision = vision; }
        virtual ~IAutoRobot() {};

    protected:
        ICollider * _vision; // <Right sigth collider, Left sight collider>
};

#endif
