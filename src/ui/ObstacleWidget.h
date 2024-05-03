#ifndef OBSTACLEWIDGET_H
#define OBSTACLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include "ObstacleGraphicItem.h"

class ObstacleGraphicItem;

class ObstacleWidget : public QWidget {
    Q_OBJECT

public:
    explicit ObstacleWidget(QWidget *parent, ObstacleGraphicItem* obstacle);

private:
    ObstacleGraphicItem* _obstacle = nullptr;
};

#endif // OBSTACLEWIDGET_H
