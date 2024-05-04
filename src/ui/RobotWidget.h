#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H

#include <QWidget>
#include "RobotGraphicItem.h"

class RobotGraphicItem;

class RobotWidget : public QWidget {
    Q_OBJECT

public:
    explicit RobotWidget(QWidget *parent, RobotGraphicItem* robot, bool isRemote);

private:
    RobotGraphicItem* _robot = nullptr;
};

#endif // ROBOTWIDGET_H
