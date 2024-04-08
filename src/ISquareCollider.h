/**
 * @file ISquareCollider.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Square Collider interface
 */

#include "ICollider.h"

using namespace std;

class ISquareCollider : public ICollider {
    public:
        virtual bool CheckCollision(ICollider * collider) = 0;
        virtual ~ISquareCollider() = 0;

    private:
        float _sideLength;
};