/**
 * @file Map.c
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Common Map implementation.
 */

#include "../headers/Map.h"

#include <QDebug>
Map::Map(int width, int height) {
    this->_width = width;
    this->_height = height;
}

void Map::Update() {
    for (uint64_t i = 0; i < this->_gameObjects.size(); i++) {
        this->_gameObjects[i]->Update();
        // qDebug() << "X: " << this->_gameObjects[i]->GetPosition()->x << " Y: " << this->_gameObjects[i]->GetPosition()->y;
    }
}

int Map::LoadJSON(string json) {
    QJsonParseError err;
    QJsonDocument doc;
    QJsonObject root;
    QJsonObject gameObject;
    QJsonArray gameObjects;
    QString str = QString::fromStdString(json);
    int width;
    int height;
    int radius;

    _gameObjects.clear();
    doc = QJsonDocument::fromJson(str.toUtf8());
    if (err.error != QJsonParseError::NoError) {
        return err.error;
    }
    root = doc.object();
    this->_width = root["width"].toInt();
    this->_height = root.value("height").toInt();
    gameObjects = root["gameObjects"].toArray();
    for (int64_t i = 0; i < gameObjects.size(); i++) {
        gameObject = gameObjects[i].toObject();
        int pos_x = gameObject["Position"].toObject()["x"].toInt();
        int pos_y = gameObject["Position"].toObject()["y"].toInt();
        int pos_angle = gameObject["Position"].toObject()["angle"].toInt();
        switch(gameObject["objectType"].toInt()) {
            case eot_gameobject: continue;
            case eot_obstacle: {
                width = gameObject["RectangleCollider"].toObject()["width"].toInt();
                height = gameObject["RectangleCollider"].toObject()["height"].toInt();
                this->AddGameObject(new Obstacle(pos_x, pos_y, pos_angle, width, height));
                break;
            }
            case eot_auto_robot: {
                IAutoRobot * ar = new AutoRobot(pos_x, pos_y, pos_angle, gameObject["CircleCollider"].toObject()["radius"].toInt());
                ar->SetSpeed(gameObject["Robot"].toObject()["speed"].toInt());
                ar->SetRotationAngle(gameObject["Robot"].toObject()["rotationAngle"].toInt());
                this->AddGameObject(ar);
                // TODO add colliders
                break;
            }
            case eot_controlled_robot: {
                IControlledRobot * cr = new ControlledRobot(pos_x, pos_y, pos_angle, gameObject["CircleCollider"].toObject()["radius"].toInt());
                cr->SetSpeed(gameObject["Robot"].toObject()["speed"].toInt());
                cr->SetRotationAngle(gameObject["Robot"].toObject()["rotationAngle"].toInt());
                cr->SetSpeedDirection(MapIntToSpeedDirection(gameObject["ControlledRobot"].toObject()["speedDirection"].toInt()));
                cr->SetRotationDirection(MapIntToRotationDirection(gameObject["ControlledRobot"].toObject()["rotationDirection"].toInt()));
                radius = gameObject["CircleCollider"].toObject()["radius"].toInt();
                this->AddGameObject(cr);
                break;
            }
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
    QJsonObject robot;
    QJsonObject autoRobot;
    QJsonObject controlledRobot;
    QJsonObject json;
    IRectangleCollider * rc;
    ICircleCollider * cc;
    IAutoRobot * ar;
    IControlledRobot * cr;

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
            ar = dynamic_cast<IAutoRobot *>(this->_gameObjects[i]);
            cc = dynamic_cast<ICircleCollider *>(ar->GetCollider());
            circleCollider.insert("radius", cc->GetRadius());
            position.insert("x", cc->GetPosition()->x);
            position.insert("y", cc->GetPosition()->y);
            position.insert("angle", cc->GetPosition()->angle);
            circleCollider.insert("Position", position);
            gameObject.insert("CircleCollider", circleCollider);
            robot.insert("speed", ar->GetSpeed());
            robot.insert("rotationAngle", ar->GetRotationAngle());
            gameObject.insert("Robot", robot);
            // TODO add colliders
            break;
        case eot_controlled_robot:
            cr = dynamic_cast<IControlledRobot *>(this->_gameObjects[i]);
            cc = dynamic_cast<ICircleCollider *>(cr->GetCollider());
            circleCollider.insert("radius", cc->GetRadius());
            position.insert("x", cc->GetPosition()->x);
            position.insert("y", cc->GetPosition()->y);
            position.insert("angle", cc->GetPosition()->angle);
            circleCollider.insert("Position", position);
            gameObject.insert("CircleCollider", circleCollider);
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


