/**
 * @file Map.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Common Map implementation.
 */

#include "../headers/Map.h"

Map::Map(int width, int height) {
    this->_width = width;
    this->_height = height;
}

void Map::Update() {
    for (uint64_t i = 0; i < this->_gameObjects.size(); i++) {
        this->_gameObjects[i]->Update();
    }
}

double Map::LoadJSON(string json) {
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
            case eot_obstacle: {
                if (pos_x == 0 || pos_y == 0 || pos_x == _width || pos_y == _height){
                    break;
                }
                width = gameObject["width"].toDouble();
                height = gameObject["height"].toDouble();
                this->AddGameObject(new Obstacle(pos_x, pos_y, pos_angle, width, height));
                break;
            }
            case eot_auto_robot: {
                IAutoRobot * ar = new AutoRobot(pos_x, pos_y, pos_angle, gameObject["radius"].toDouble());
                ar->SetSpeed(gameObject["Robot"].toObject()["speed"].toDouble());
                ar->SetRotationAngle(gameObject["Robot"].toObject()["rotationAngle"].toDouble());
                this->AddGameObject(ar);
                // TODO add colliders
                break;
            }
            case eot_controlled_robot: {
                IControlledRobot * cr = new ControlledRobot(pos_x, pos_y, pos_angle, gameObject["radius"].toDouble());
                cr->SetSpeed(gameObject["Robot"].toObject()["speed"].toDouble());
                cr->SetRotationAngle(gameObject["Robot"].toObject()["rotationAngle"].toDouble());
                cr->SetSpeedDirection(MapIntToSpeedDirection(gameObject["ControlledRobot"].toObject()["speedDirection"].toDouble()));
                cr->SetRotationDirection(MapIntToRotationDirection(gameObject["ControlledRobot"].toObject()["rotationDirection"].toDouble()));
                radius = gameObject["CircleCollider"].toObject()["radius"].toDouble();
                this->AddGameObject(cr);
                break;
            }
        }
    }
    return 0;
}

string Map::SaveJSON() {
    QJsonArray gameObjects;
    QJsonObject position;
    QJsonObject robot;
    QJsonObject autoRobot;
    QJsonObject controlledRobot;
    QJsonObject json;
    IAutoRobot * ar;
    IControlledRobot * cr;

    json.insert("width", this->_width);
    json.insert("height", this->_height);

    for (uint64_t i = 0; i < this->_gameObjects.size(); i++) {
        QJsonObject gameObject;
        qDebug() << "Saving object: " << this->_gameObjects[i];
        position.insert("x", this->_gameObjects[i]->GetPosition()->x);
        position.insert("y", this->_gameObjects[i]->GetPosition()->y);
        position.insert("angle", this->_gameObjects[i]->GetPosition()->angle);
        gameObject.insert("Position", position);
        gameObject.insert("objectType", this->_gameObjects[i]->GetObjectType());
        switch (this->_gameObjects[i]->GetObjectType()) {
            case eot_gameobject: continue;
            case eot_obstacle:
                gameObject.insert("width", dynamic_cast<IObstacle *>(this->_gameObjects[i])->GetWidth());
                gameObject.insert("height", dynamic_cast<IObstacle *>(this->_gameObjects[i])->GetHeight());
                position.insert("x", this->_gameObjects[i]->GetPosition()->x);
                position.insert("y", this->_gameObjects[i]->GetPosition()->y);
                position.insert("angle", this->_gameObjects[i]->GetPosition()->angle);
                // rectangleCollider.insert("Position", position);
                // gameObject.insert("RectangleCollider", rectangleCollider);
                break;
            case eot_auto_robot:
                ar = dynamic_cast<IAutoRobot *>(this->_gameObjects[i]);
                gameObject.insert("radius", dynamic_cast<IAutoRobot *>(this->_gameObjects[i])->GetRadius());
                position.insert("x", this->_gameObjects[i]->GetPosition()->x);
                position.insert("y", this->_gameObjects[i]->GetPosition()->y);
                position.insert("angle", this->_gameObjects[i]->GetPosition()->angle);
                robot.insert("speed", ar->GetSpeed());
                robot.insert("rotationAngle", ar->GetRotationAngle());
                gameObject.insert("Robot", robot);
                // TODO add colliders
                break;
            case eot_controlled_robot:
                cr = dynamic_cast<IControlledRobot *>(this->_gameObjects[i]);
                gameObject.insert("radius", dynamic_cast<IRobot *>(this->_gameObjects[i])->GetRadius());
                position.insert("x", this->_gameObjects[i]->GetPosition()->x);
                position.insert("y", this->_gameObjects[i]->GetPosition()->y);
                position.insert("angle", this->_gameObjects[i]->GetPosition()->angle);
                robot.insert("speed", cr->GetSpeed());
                robot.insert("rotationAngle", cr->GetRotationAngle());
                gameObject.insert("Robot", robot);
                controlledRobot.insert("speedDirection", cr->GetSpeedDirection());
                controlledRobot.insert("rotationDirection", cr->GetRotationDirection());
                gameObject.insert("ControlledRobot", controlledRobot);
                break;
        }
        gameObjects.push_back(gameObject);
    }
    json.insert("gameObjects", gameObjects);

    return QJsonDocument(json).toJson(QJsonDocument::Compact).toStdString();
}


void Map::AddGameObject(IGameObject * gameObject) {
    gameObject->SetId(this->_gameObjects.size());
    gameObject->SetMap(this);
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
    return this->_gameObjects;
}

SpeedDirection MapIntToSpeedDirection(int i) {
    switch (i) {
        case 0: return esd_none;
        case 1: return esd_forward;
    }
}

RotationDirection MapIntToRotationDirection(int i) {
    switch (i) {
        case -1: return erd_right;
        case 0: return erd_none;
        case 1: return erd_left;
    }
}

std::pair<int, int> Map::getSize() {
    return make_pair(this->_width, this->_height);
}


