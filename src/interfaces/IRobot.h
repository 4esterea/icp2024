/**
 * @file IRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Robot interface
 */

#ifndef __IROBOT_H__
#define __IROBOT_H__

#include "IGameObject.h"

class IRobot : public IGameObject {
    public:
        virtual void Update() = 0;
        virtual int GetSpeed() = 0;
        virtual void SetSpeed(int speed) = 0;
        virtual int GetRotationAngle() = 0;
        virtual void SetRotationAngle(int rotationAngle) = 0;
        virtual ~IRobot() {};

    protected:
        int _speed; // Constant through run
        int _rotationAngle; // Constant through run
};

#endif
