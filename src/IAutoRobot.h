/**
 * @file IAutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Auto Robot interface
 */

#include <utility>

#include "IRobot.h"

using namespace std;

class IAutoRobot : public IRobot {
    public:
        virtual void Update() = 0;
        virtual ~IAutoRobot() = 0;

    private:
        pair<ICollider, ICollider> _collisionBox; // <Body collider, Sight collider>
};