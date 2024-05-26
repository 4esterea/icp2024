/**
* @file mainwindow.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Header file of mainwindow.cpp
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include <QFileInfo>
#include "src/ui/clickableLabel.h"
#include "src/headers/Map.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
 * @brief Constructor for MainWindow class.
 *
 * @param parent The parent QWidget object.
 */
explicit MainWindow(QWidget *parent = nullptr);

/**
 * @brief Destructor for MainWindow class.
 */
~MainWindow();

/**
 * @brief Checks if obstacle mode is active.
 *
 * @return True if obstacle mode is active, false otherwise.
 */
bool isObstacleMode();

/**
 * @brief Checks if auto robot mode is active.
 *
 * @return True if auto robot mode is active, false otherwise.
 */
bool isAutoRobotMode();

/**
 * @brief Checks if RC robot mode is active.
 *
 * @return True if RC robot mode is active, false otherwise.
 */
bool isRCRobotMode();

/**
 * @brief Checks if editing is enabled.
 *
 * @return True if editing is enabled, false otherwise.
 */
bool isEditingEnabled();

/**
 * @brief Checks if the default state is active.
 *
 * @return True if the default state is active, false otherwise.
 */
bool isDefault();

/**
 * @brief Checks if the simulation is launched.
 *
 * @return True if the simulation is launched, false otherwise.
 */
bool isLaunched();

/**
 * @brief Sets the default editing state.
 */
void setDefaultEditingState();

/**
 * @brief Runs the simulation.
 */
void RunSimulation();

/**
 * @brief Gets the map object.
 *
 * @return A pointer to the Map object.
 */
Map* getMap();

private slots:
    void on_pushButtonEdit_clicked(bool checked);
    void on_pushButtonLaunch_clicked(bool checked);
    void on_pushButtonPause_clicked(bool checked);
    void on_pushButtonLoad_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonNew_clicked();
    void on_pushButtonCancel_clicked();
    void on_pushButtonConfirm_clicked();
    void on_autoRobotIcon_clicked();
    void on_RCRobotIcon_clicked();
    void on_obstacleIcon_clicked();

private:
    Ui::MainWindow *ui;
    void setUiDefaultState();
    void loadLevel();
    QString _fileToOpen;
    QString _fileToSave;
    std::string _defaultJSON = R"({"gameObjects":[{"Position":{"angle":0,"x":0,"y":0},"objectType":1,"width":1000},{"Position":{"angle":0,"x":1000,"y":0},"objectType":1,"width":1000},{"Position":{"angle":0,"x":0,"y":0},"objectType":1,"width":1},{"Position":{"angle":0,"x":0,"y":1000},"objectType":1,"width":1}],"height":1000,"width":1000})";
    bool _isLayoutSet = false;
    bool _editingEnabled;
    bool _isLaunched;
    bool _isPaused;
    bool _turnRight;
    bool _robotIsChosen;
    bool _RCRobotIsChosen;
    bool _obstacleIsChosen;
    QTimer * _timer;
    Map* _map;
};

#endif // MAINWINDOW_H
