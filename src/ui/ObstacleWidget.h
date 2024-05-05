/**
* @file ObstacleWidget.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Declaration of ObstacleWidget
 */



#ifndef OBSTACLEWIDGET_H
#define OBSTACLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include "ObstacleGraphicItem.h"

class ObstacleGraphicItem;

class ObstacleWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for ObstacleWidget class.
     *
     * @param parent The parent QWidget object.
     * @param obstacle The ObstacleGraphicItem object.
     */
    explicit ObstacleWidget(QWidget *parent, ObstacleGraphicItem* obstacle);

private:
    ObstacleGraphicItem* _obstacle = nullptr;
};

#endif // OBSTACLEWIDGET_H
