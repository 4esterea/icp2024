/**
 * @file Map.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Common Map implementation.
 */

#include "../headers/Map.h"

Map::Map(double width, double height) {
    this->_width = width;
    this->_height = height;
}

void Map::Update() {
    for (uint64_t i = 0; i < this->_gameObjects.size(); i++) {
        this->_gameObjects[i]->Update();
    }
}

int Map::LoadJSON(string json) {
    QJsonParseError err;
    QJsonDocument doc;
    QJsonObject root;
    QJsonObject gameObject;
    QJsonArray gameObjects;
    QString str = QString::fromStdString(json);
    _gameObjects.clear();
    doc = QJsonDocument::fromJson(str.toUtf8());
    if (err.error != QJsonParseError::NoError) {
        return err.error;
    }
    root = doc.object();
    this->_width = root["width"].toDouble();
    this->_height = root.value("height").toDouble();
    gameObjects = root["gameObjects"].toArray();
    for (int64_t i = 0; i < gameObjects.size(); i++) {
        gameObject = gameObjects[i].toObject();
        double pos_x = gameObject["Position"].toObject()["x"].toDouble();
        double pos_y = gameObject["Position"].toObject()["y"].toDouble();
        double pos_angle = gameObject["Position"].toObject()["angle"].toDouble();
        switch(gameObject["objectType"].toInt()) {
            case eot_null: continue;
            case eot_obstacle:
                double width = gameObject["RectangleCollider"].toObject()["width"].toDouble();
                double height = gameObject["RectangleCollider"].toObject()["height"].toDouble();
                this->AddGameObject(new Obstacle(pos_x, pos_y, pos_angle, width, height));
                break;
        }
    }


    return 0;
}

string Map::SaveJSON() {
    QJsonArray gameObjects;
    QJsonObject gameObject;
    QJsonObject position;
    QJsonObject rectangleCollider;
    QJsonObject json;

    json.insert("width", this->_width);
    json.insert("height", this->_height);

    for (uint64_t i = 0; i < this->_gameObjects.size(); i++) {
        qDebug() << "Saving object: " << this->_gameObjects[i];
        position.insert("x", this->_gameObjects[i]->GetPosition()->x);
        position.insert("y", this->_gameObjects[i]->GetPosition()->y);
        position.insert("angle", this->_gameObjects[i]->GetPosition()->angle);
        gameObject.insert("Position", position);
        gameObject.insert("objectType", this->_gameObjects[i]->GetObjectType());
        switch (this->_gameObjects[i]->GetObjectType()) {
            case eot_null: continue;
            case eot_obstacle:
                IRectangleCollider * rc = dynamic_cast<IRectangleCollider *>(this->_gameObjects[i]->GetCollider());
                rectangleCollider.insert("width", rc->GetWidth());
                rectangleCollider.insert("height", rc->GetHeight());
                position.insert("x", rc->GetPosition()->x);
                position.insert("y", rc->GetPosition()->y);
                position.insert("angle", rc->GetPosition()->angle);
                rectangleCollider.insert("Position", position);
                gameObject.insert("RectangleCollider", rectangleCollider);
                break;
        }
        gameObjects.push_back(gameObject);
    }
    json.insert("gameObjects", gameObjects);

    return QJsonDocument(json).toJson(QJsonDocument::Compact).toStdString();
}



void Map::AddGameObject(IGameObject * gameObject) {
    this->_gameObjects.push_back(gameObject);
}

void Map::RemoveGameObject(IGameObject * gameObject) {
    for (uint64_t i = 0; i < this->_gameObjects.size(); i++) {
        if (this->_gameObjects[i] == gameObject) {
            this->_gameObjects.erase(this->_gameObjects.begin() + i);
            return;
        }
    }
}

const std::vector<IGameObject *> &Map::getGameObjects() const {
    return _gameObjects;
}
