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

class Map: public IMap {
    public:
        void AddGameObject(IGameObject * gameObject);
        void RemoveGameObject(IGameObject * gameObject);
        std::pair<int, int> getSize();
        void Update();
        double LoadJSON(string json);
        string SaveJSON();
        const std::vector<IGameObject*>& getGameObjects() const override;
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
