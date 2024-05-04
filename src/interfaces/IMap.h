/**
 * @file IMap.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Map interface
 */

#ifndef __IMAP_H__
#define __IMAP_H__

#include <string>
#include <vector>
#include "IGameObject.h"

using namespace std;

class IMap {
    public:
        virtual void AddGameObject(IGameObject * gameObject) = 0;
        virtual void Update() = 0;
        virtual int LoadJSON(string json) = 0;
        virtual string SaveJSON() = 0;
        virtual const std::vector<IGameObject*>& getGameObjects() const = 0;
        virtual ~IMap() {};

    protected:
        int _width;
        int _height;
        std::vector<IGameObject *> _gameObjects;
};

#endif
