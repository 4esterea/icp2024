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
        virtual ~IAutoRobot() {};

    protected:
        pair<ICollider, ICollider> * _collisionBox; // <Right sigth collider, Left sight collider>
};

#endif
