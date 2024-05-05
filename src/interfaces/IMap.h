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

class IMap {
    public:
    /**
     * @brief Adds a game object to the map.
     *
     * @param gameObject A pointer to the game object to add.
     */
    virtual void AddGameObject(IGameObject * gameObject) = 0;

    /**
     * @brief Updates the state of the map.
     */
    virtual void Update() = 0;

    /**
     * @brief Loads the map from a JSON string.
     *
     * @param json The JSON string to load the map from.
     * @return The result of the loading operation.
     */
    virtual double LoadJSON(string json) = 0;

    /**
     * @brief Saves the map to a JSON string.
     *
     * @return The JSON string representing the map.
     */
    virtual string SaveJSON() = 0;

    /**
     * @brief Gets the game objects in the map.
     *
     * @return A vector of pointers to the game objects in the map.
     */
    virtual const std::vector<IGameObject*>& getGameObjects() const = 0;

    /**
     * @brief Virtual destructor for the IMap interface.
     */
    virtual ~IMap() {};

    protected:
        double _width;
        double _height;
        std::vector<IGameObject *> _gameObjects;
};

#endif
