/**
 * @file IObstacle.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Obstacle interface
 */

#include "IGameObject.h"

using namespace std;

class IObstacle : public IGameObject {
    public:
        virtual ~IObstacle() = 0;
};