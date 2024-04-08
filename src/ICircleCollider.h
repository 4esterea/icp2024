/**
 * @file ICircleCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Circle Collider interface
 */

#include "ICollider.h"

using namespace std;

class ICircleCollider : public ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~ICircleCollider() = 0;

    private:
        float _radius;
};