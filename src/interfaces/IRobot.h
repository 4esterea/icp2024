/**
 * @file IRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Robot doubleerface
 */

#ifndef __IROBOT_H__
#define __IROBOT_H__

#include "IGameObject.h"
#include "IRectangleCollider.h"

class IRobot : public IGameObject {
    public:
        IRectangleCollider * GetVision() { return this->_vision; }
        void SetVision(IRectangleCollider * vision) { this->_vision = vision; }
        RotationDirection GetCollisionBehavior() { return this->_collisionBehavior; }
        void SetCollisionBehavior(RotationDirection collisionBehavior) { this->_collisionBehavior = collisionBehavior; }
        virtual void Update() = 0;
        virtual double GetSpeed() = 0;
        virtual void SetSpeed(double speed) = 0;
        virtual double GetRotationAngle() = 0;
        virtual void SetRotationAngle(double rotationAngle) = 0;
        virtual ~IRobot() {};

    protected:
        double _speed; // Constant through run
        double _rotationAngle; // Constant through run
        IRectangleCollider * _vision; // <Right sigth collider, Left sight collider>
        RotationDirection _collisionBehavior;
};

#endif
