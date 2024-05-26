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
#include "../headers/Obstacle.h"
#include "../headers/AutoRobot.h"
#include "../headers/ControlledRobot.h"

 /**
 * @brief The Map class Map where all gameobjects are located
 */
class Map: public IMap {
public:
    /**
     * @brief Map Constructor of map
     * @param width Width
     * @param height Height
     */
    Map(int width, int height);
    /**
     * @brief AddGameObject Adds gameobject to the map
     * @param gameObject New gameobject
     */
    void AddGameObject(IGameObject * gameObject);
    /**
     * @brief RemoveGameObject Removes game object from the map
     * @param gameObject Gameobject to be removed
     */
    void RemoveGameObject(IGameObject * gameObject);
    /**
     * @brief getSize Returns size of map
     * @return Pair of width and heigh
     */
    std::pair<int, int> getSize();
    /**
     * @brief Update Updates all gameobjects on the map
     */
    void Update();
    /**
     * @brief LoadJSON Initializes map from json
     * @param json Map in json
     * @return Error if occured
     */
    double LoadJSON(string json);
    /**
     * @brief SaveJSON Saves current map state to json
     * @return Json string
     */
    string SaveJSON();
    /**
     * @brief getGameObjects Returns gameobjects that are currently on the map
     * @return Vector of gameobjects
     */
    const std::vector<IGameObject*>& getGameObjects() const override;
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
