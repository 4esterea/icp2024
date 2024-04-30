QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0 #0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/ui/HoverableObstacle.cpp \
    src/ui/clickableLabel.cpp\
    src/main.cpp \
    src/mainwindow.cpp\
    src/common/Obstacle.cpp \
    src/common/Map.cpp \
    src/common/Position.cpp \
    src/common/RectangleCollider.cpp\
    src/ui/Viewport.cpp


HEADERS += \
    src/mainwindow.h\
    src/ui/HoverableObstacle.h \
    src/ui/clickableLabel.h\
    src/ui/Viewport.h\
    src/IAutoRobot.h\
    src/ICircleCollider.h\
    src/ICollider.h\
    src/IControlledRobot.h\
    src/IGameObject.h\
    src/IPosition.h\
    src/IRobot.h\
    src/ISquareCollider.h\
    src/headers/Map.h\
    src/headers/RectangleCollider.h\
    src/headers/Position.h\
    src/headers/Obstacle.h\
    src/headers/types.h

FORMS += \
    src/mainwindow.ui

OBJECTS_DIR=objs/
MOC_DIR=moc/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
