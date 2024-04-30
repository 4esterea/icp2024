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
#include "../interfaces/IMap.h"
#include "../interfaces/IRectangleCollider.h"
#include "../headers/Obstacle.h"

class Map: public IMap {
    public:
        void AddGameObject(IGameObject * gameObject);
        void Update();
        int LoadJSON(string json);
        string SaveJSON();
        const std::vector<IGameObject*>& GetGameObjects() const override;
        Map(double width, double height);
};

#endif
