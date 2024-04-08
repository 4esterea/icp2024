/**
 * @file IMap.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Map interface
 */

#include "IGameObject.h"

using namespace std;

class IMap {
    public:
        virtual void AddGameObject(IGameObject * gameObject) = 0;
        virtual void Update() = 0;
        virtual ~IMap() = 0;

    private:
        float _width;
        float _height;
        IGameObject * _gameObjects[];
};