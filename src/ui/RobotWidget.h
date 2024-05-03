#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H

#include <QWidget>
#include "RobotGraphicItem.h"

class RobotGraphicItem;

class RobotWidget : public QWidget {
    Q_OBJECT

public:
    explicit RobotWidget(QWidget *parent, RobotGraphicItem* autoRobot, bool isRemote);

private:
    RobotGraphicItem* _autoRobot = nullptr;
};

#endif // ROBOTWIDGET_H
