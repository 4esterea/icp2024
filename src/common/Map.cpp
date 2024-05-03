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
    double width;
    double height;
    double radius;

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
        case eot_gameobject: continue;
        case eot_obstacle:
            width = gameObject["RectangleCollider"].toObject()["width"].toDouble();
            height = gameObject["RectangleCollider"].toObject()["height"].toDouble();
            this->AddGameObject(new Obstacle(pos_x, pos_y, pos_angle, width, height));
            break;
        case eot_auto_robot:
            radius = gameObject["CircleCollider"].toObject()["radius"].toDouble();
            this->AddGameObject(new AutoRobot(pos_x, pos_y, pos_angle, radius));
            // TODO add colliders
            break;
        case eot_controlled_robot:
            radius = gameObject["CircleCollider"].toObject()["radius"].toDouble();
            this->AddGameObject(new ControlledRobot(pos_x, pos_y, pos_angle, radius));
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
    QJsonObject circleCollider;
    QJsonObject json;
    IRectangleCollider * rc;
    ICircleCollider * cc;

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
        case eot_gameobject: continue;
        case eot_obstacle:
            rc = dynamic_cast<IRectangleCollider *>(this->_gameObjects[i]->GetCollider());
            rectangleCollider.insert("width", rc->GetWidth());
            rectangleCollider.insert("height", rc->GetHeight());
            position.insert("x", rc->GetPosition()->x);
            position.insert("y", rc->GetPosition()->y);
            position.insert("angle", rc->GetPosition()->angle);
            rectangleCollider.insert("Position", position);
            gameObject.insert("RectangleCollider", rectangleCollider);
            break;
        case eot_auto_robot:
            cc = dynamic_cast<ICircleCollider *>(this->_gameObjects[i]->GetCollider());
            circleCollider.insert("radius", cc->GetRadius());
            position.insert("x", cc->GetPosition()->x);
            position.insert("y", cc->GetPosition()->y);
            position.insert("angle", cc->GetPosition()->angle);
            circleCollider.insert("Position", position);
            gameObject.insert("CircleCollider", circleCollider);
            // TODO add colliders
            break;
        case eot_controlled_robot:
            cc = dynamic_cast<ICircleCollider *>(this->_gameObjects[i]->GetCollider());
            circleCollider.insert("radius", cc->GetRadius());
            position.insert("x", cc->GetPosition()->x);
            position.insert("y", cc->GetPosition()->y);
            position.insert("angle", cc->GetPosition()->angle);
            circleCollider.insert("Position", position);
            gameObject.insert("CircleCollider", circleCollider);
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
