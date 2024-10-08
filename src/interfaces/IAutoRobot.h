/**
 * @file IAutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Auto Robot interface
 */

#ifndef __IAUTOROBOT_H__
#define __IAUTOROBOT_H__

#include <utility>

#include "IRobot.h"
#include "IRectangleCollider.h"
#include "IQtCircleCollider.h"

using namespace std;

class IAutoRobot : public IRobot {
    public:
        virtual ~IAutoRobot() {};
};

#endif
