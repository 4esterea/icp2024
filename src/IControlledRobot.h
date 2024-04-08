/**
 * @file IControlledRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Controlled Robot interface
 */

#include <utility>

#include "IRobot.h"

using namespace std;

class IControlledRobot : public IRobot {
    public:
        virtual void SetSpeedDirection(SpeedDirection speedDirection) = 0;
        virtual void SetRotationDirection(RotationDirection rotationDirection) = 0;
        virtual void Update() = 0;
        virtual ~IControlledRobot() = 0;

    private:
        SpeedDirection _speedDirection;
        RotationDirection _rotationDirection;
        ICollider * _collisionBox; // Body collider
};