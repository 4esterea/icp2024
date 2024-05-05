QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0 #0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/common/AutoRobot.cpp \
    src/common/CircleCollider.cpp \
    src/common/CollisionChecker.cpp \
    src/common/ControlledRobot.cpp \
    src/ui/ObstacleGraphicItem.cpp \
    src/ui/ObstacleWidget.cpp \
    src/ui/RobotGraphicItem.cpp \
    src/ui/RobotWidget.cpp \
    src/ui/clickableLabel.cpp\
    src/main.cpp \
    src/mainwindow.cpp\
    src/common/Obstacle.cpp \
    src/common/Map.cpp \
    src/common/Position.cpp \
    src/common/RectangleCollider.cpp\
    src/ui/Viewport.cpp


HEADERS += \
    src/headers/AutoRobot.h \
    src/headers/CircleCollider.h \
    src/headers/CollisionChecker.h \
    src/headers/ControlledRobot.h \
    src/interfaces/IAutoRobot.h \
    src/interfaces/ICircleCollider.h \
    src/interfaces/ICollider.h \
    src/interfaces/IControlledRobot.h \
    src/interfaces/IGameObject.h \
    src/interfaces/IMap.h \
    src/interfaces/IObstacle.h \
    src/interfaces/IPosition.h \
    src/interfaces/IRectangleCollider.h \
    src/interfaces/IRobot.h \
    src/main.h \
    src/mainwindow.h\
    src/ui/ObstacleGraphicItem.h \
    src/ui/ObstacleWidget.h \
    src/ui/RobotGraphicItem.h \
    src/ui/RobotWidget.h \
    src/ui/clickableLabel.h\
    src/ui/Viewport.h\
    src/headers/Map.h\
    src/headers/RectangleCollider.h\
    src/headers/Position.h\
    src/headers/Obstacle.h\
    src/headers/types.h

FORMS += \
    src/mainwindow.ui


RESOURCES += \
    src/resources.qrc


OBJECTS_DIR=objs/
MOC_DIR=moc/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
