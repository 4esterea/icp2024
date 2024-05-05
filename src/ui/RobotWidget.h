/**
* @file RobotWidget.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Declaration of RobotWidget
 */


#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H

#include <QWidget>
#include "RobotGraphicItem.h"

class RobotGraphicItem;

class RobotWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for RobotWidget class.
     *
     * @param parent The parent QWidget object.
     * @param robot The RobotGraphicItem object.
     * @param isRemote A boolean indicating whether the robot is remote.
     */
     explicit RobotWidget(QWidget *parent, RobotGraphicItem* robot, bool isRemote);

private:
    RobotGraphicItem* _robot = nullptr;
};

#endif // ROBOTWIDGET_H
