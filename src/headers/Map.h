/**
 * @file Map.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Common Map declaration.
 */

#ifndef __MAP_H__
#define __MAP_H__

#include <string>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QString>
#include <QDebug>
#include "../interfaces/IMap.h"
#include "../interfaces/IRectangleCollider.h"
#include "../interfaces/ICircleCollider.h"
#include "../interfaces/ISquareCollider.h"
#include "../headers/Obstacle.h"
#include "../headers/AutoRobot.h"
#include "../headers/ControlledRobot.h"

class Map: public IMap {
public:
    /**
   * @brief Adds a game object to the map.
   *
   * @param gameObject The game object to add.
   */
    void AddGameObject(IGameObject * gameObject);

    /**
     * @brief Removes a game object from the map.
     *
     * @param gameObject The game object to remove.
     */
    void RemoveGameObject(IGameObject * gameObject);

    /**
     * @brief Gets the size of the map.
     *
     * @return A pair of integers representing the width and height of the map.
     */
    std::pair<int, int> getSize();

    /**
     * @brief Updates the state of the map.
     */
    void Update();

    /**
     * @brief Loads the map from a JSON string.
     *
     * @param json The JSON string to load the map from.
     * @return A double representing the success of the operation.
     */
    double LoadJSON(string json);

    /**
     * @brief Saves the map to a JSON string.
     *
     * @return The JSON string representing the map.
     */
    string SaveJSON();

    /**
     * @brief Gets the game objects in the map.
     *
     * @return A vector of pointers to the game objects in the map.
     */
    const std::vector<IGameObject*>& getGameObjects() const override;

    /**
     * @brief Constructor for the Map class.
     *
     * @param width The width of the map.
     * @param height The height of the map.
     */
    Map(int width, int height);
};

/**
 * @brief Converts an integer to a speed direction.
 *
 * @param i The integer to convert.
 * @return The corresponding speed direction.
 */
SpeedDirection MapIntToSpeedDirection(int i);

/**
 * @brief Converts an integer to a rotation direction.
 *
 * @param i The integer to convert.
 * @return The corresponding rotation direction.
 */
RotationDirection MapIntToRotationDirection(int i);

#endif
