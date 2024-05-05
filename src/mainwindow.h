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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool isObstacleMode();
    bool isAutoRobotMode();
    bool isRCRobotMode();
    bool isEditingEnabled();
    bool isDefault();
    void setDefaultEditingState();
    void RunSimulation();
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
    QString _fileToOpen = "lvl/lvl1.json";
    QString _fileToSave;
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
