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
#include "IQtCircleCollider.h"
#include "IQtCollider.h"

class IRobot : public IGameObject {
    public:
        IQtCollider * GetVision() { return this->_vision; }
        void SetVision(IQtCollider * vision) { this->_vision = vision; }
        RotationDirection GetCollisionBehavior() { return this->_collisionBehavior; }
        void SetCollisionBehavior(RotationDirection collisionBehavior) { this->_collisionBehavior = collisionBehavior; }
        IQtCircleCollider * GetCollider() { return dynamic_cast<IQtCircleCollider *>(this->_collider); };
        double GetRadius() { return this->_radius; }
        void SetRadius(double radius) { this->_radius = radius; }
        virtual void Update() = 0;
        virtual double GetSpeed() = 0;
        virtual void SetSpeed(double speed) = 0;
        virtual double GetRotationAngle() = 0;
        virtual void SetRotationAngle(double rotationAngle) = 0;
        virtual ~IRobot() {};

    protected:
        double _radius;
        double _speed; // Constant through run
        double _rotationAngle; // Constant through run
        IQtCollider * _vision; // <Right sigth collider, Left sight collider>
        RotationDirection _collisionBehavior;
};

#endif
