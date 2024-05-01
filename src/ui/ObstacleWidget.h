#ifndef OBSTACLEWIDGET_H
#define OBSTACLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include "HoverableObstacle.h"

class HoverableObstacle;

class ObstacleWidget : public QWidget {
    Q_OBJECT

public:
    explicit ObstacleWidget(QWidget *parent, HoverableObstacle* obstacle);
private:
    HoverableObstacle* _obstacle = nullptr;
};


#endif // OBSTACLEWIDGET_H
