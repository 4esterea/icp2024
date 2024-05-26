/**
 * @file IMap.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Map interface
 */

#ifndef __IMAP_H__
#define __IMAP_H__

#include <string>
#include <vector>
#include "IGameObject.h"

using namespace std;

/**
 * @brief The IMap class Map
 */
class IMap {
public:
    /**
     * @brief AddGameObject Adds game object to the map
     * @param gameObject New game object
     */
    virtual void AddGameObject(IGameObject * gameObject) = 0;
    /**
     * @brief Update Updates all gameobjects on the map
     */
    virtual void Update() = 0;
    /**
     * @brief LoadJSON Initializes map from json
     * @param json Map in json
     * @return Error if occured
     */
    virtual double LoadJSON(string json) = 0;
    /**
     * @brief SaveJSON Saves current map state to json
     * @return Json string
     */
    virtual string SaveJSON() = 0;
    /**
     * @brief getGameObjects Returns gameobjects that are currently on the map
     * @return Vector of gameobjects
     */
    virtual const std::vector<IGameObject*>& getGameObjects() const = 0;
    /**
     * @brief ~IMap Virtual destructor
     */
    virtual ~IMap() {};

protected:
    double _width;
    double _height;
    std::vector<IGameObject *> _gameObjects;
};

#endif
