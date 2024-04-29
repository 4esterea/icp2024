QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0 #0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/common/Map.cpp \
    src/common/Obstacle.cpp \
    src/common/Position.cpp \
    src/common/RectangleCollider.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/headers/Map.h \
    src/headers/Obstacle.h \
    src/headers/Position.h \
    src/headers/RectangleCollider.h \
    src/headers/types.h \
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
    src/interfaces/ISquareCollider.h \
    src/main.h \
    src/mainwindow.h

FORMS += \
    src/mainwindow.ui

OBJECTS_DIR=objs/
MOC_DIR=moc/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
