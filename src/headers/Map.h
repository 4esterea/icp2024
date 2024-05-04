/**
 * @file Map.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
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
        void AddGameObject(IGameObject * gameObject);
        void RemoveGameObject(IGameObject * gameObject);
        std::pair<int, int> getSize();
        void Update();
        int LoadJSON(string json);
        string SaveJSON();
        const std::vector<IGameObject*>& getGameObjects() const override;
        Map(int width, int height);
};


SpeedDirection MapIntToSpeedDirection(int i);

RotationDirection MapIntToRotationDirection(int i);

#endif
