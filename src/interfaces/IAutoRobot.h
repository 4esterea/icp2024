/**
 * @file IAutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Auto Robot doubleerface
 */

#ifndef __IAUTOROBOT_H__
#define __IAUTOROBOT_H__

#include <utility>

#include "IRobot.h"
#include "IRectangleCollider.h"

using namespace std;

class IAutoRobot : public IRobot {
    public:
        IRectangleCollider * GetVision() { return this->_vision; }
        void SetVision(IRectangleCollider * vision) { this->_vision = vision; }
        virtual ~IAutoRobot() {};

    protected:
        IRectangleCollider * _vision; // <Right sigth collider, Left sight collider>
};

#endif
