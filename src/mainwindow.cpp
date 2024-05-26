/**
* @file mainwindow.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Implementation of mainwindow
 */



#include "mainwindow.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QFile>
#include <QIODevice>
#include <QPixmap>
#include "ui/Viewport.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUiDefaultState();
    this->_timer = new QTimer(this);
    connect(this->_timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::RunSimulation));

    loadLevel();
}


void MainWindow::loadLevel()
{
    if (_isLayoutSet){
        QFile file(_fileToOpen);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open the file\n";
            return;
        }
        std::string json = file.readAll().toStdString();
        _map->LoadJSON(json);
    } else {
        _map->LoadJSON(_defaultJSON);
        _isLayoutSet = true;
    }
    ui->viewport->drawAll();
}

void MainWindow::setUiDefaultState()
{
	QFont font("Ubuntu");
    this->setFont(font);
    this->setWindowTitle("2d robot simulator");
    ui->viewport->setRenderHint(QPainter::Antialiasing);
    this->setFixedSize(this->size());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->labelCurrent->setText("Current Layout: <none>");
    ui->pushButtonEdit->setText("EDIT");
    ui->pushButtonLaunch->setText("LAUNCH");
    ui->pushButtonPause->setText("PAUSE");
    ui->pushButtonLaunch->setFixedWidth(150);
    ui->pushButtonPause->setFixedWidth(70);
    ui->pushButtonPause->hide();
    ui->newMapWidget->hide();
    ui->newMapWidget->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->newMapWidget->setFixedSize(ui->newMapWidget->size());
    ui->newMapWidget->setWindowTitle("Create New Map");
    _editingEnabled = false;
    _isLaunched = false;
    _isPaused = false;
    _turnRight = false;
    _robotIsChosen = _RCRobotIsChosen = _obstacleIsChosen = false;
    QPixmap robotPm(":/media/robot.png");
    QPixmap obstaclePm(":/media/obstacle.png");
    QPixmap RCRobotPm(":/media/RCrobot.png");
    ui->autoRobotIcon->setPixmap(robotPm);
    ui->autoRobotIcon->setScaledContents(true);
    ui->autoRobotIcon->setMaximumSize(50, 50);
    ui->RCRobotIcon->setPixmap(RCRobotPm);
    ui->RCRobotIcon->setScaledContents(true);
    ui->RCRobotIcon->setMaximumSize(50, 50);
    ui->obstacleIcon->setPixmap(obstaclePm);
    ui->obstacleIcon->setScaledContents(true);
    ui->obstacleIcon->setMaximumSize(50, 50);
    ui->editMode->hide();
    this->_map = new Map(0, 0);
}

MainWindow::~MainWindow()
{
    if (_fileToSave == "./temp.json"){
        QFile::remove(_fileToSave);
    }
    delete ui;
}


void MainWindow::on_pushButtonEdit_clicked(bool checked)
{
    _editingEnabled = !_editingEnabled;
    _robotIsChosen = _RCRobotIsChosen = _obstacleIsChosen = false;
    if (_editingEnabled){
        qDebug() << "Editing is Enabled";
        this->setWindowTitle("2d robot simulator [EDITING]");
        ui->pushButtonEdit->setText("STOP EDITING");
        ui->pushButtonLaunch->setEnabled(0);
        ui->editMode->show();
    } else {
        ui->pushButtonEdit->setText("EDIT");
        qDebug() << "Editing is Disabled";
        this->setWindowTitle("2d robot simulator");
        ui->pushButtonLaunch->setEnabled(1);
        ui->editMode->hide();
        ui->viewport->hideAllSettings();
    }
}

void MainWindow::on_pushButtonLaunch_clicked(bool checked)
{
    _fileToSave = "./temp.json";
    QFile file(_fileToSave);
    _isLaunched = !_isLaunched;
    if (_isLaunched){
       string json = _map->SaveJSON();
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Failed to open the file\n";
            return;
        }
        file.write(json.c_str());
        file.close();

        qDebug() << "Simulation is running";
        this->setWindowTitle("2d robot simulator [RUNNING]");
        ui->pushButtonLaunch->setText("STOP");
        ui->pushButtonLaunch->setFixedWidth(70);
        ui->pushButtonEdit->setEnabled(0);
        ui->pushButtonLoad->setEnabled(0);
        ui->pushButtonSave->setEnabled(0);
        ui->pushButtonNew->setEnabled(0);
        ui->pushButtonPause->show();
		ui->viewport->setFocus();
        this->_timer->start(FRAME_TIMEGAP_MS);
    } else {

        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open the file: " << file.errorString();
            return;
        }
        std::string tempSave = file.readAll().toStdString();
        _map->LoadJSON(tempSave);
        ui->viewport->drawAll();
        file.close();
        QFile::remove(_fileToSave);

        qDebug() << "Simulation has been stopped";
        this->setWindowTitle("2d robot simulator");
        ui->pushButtonLaunch->setText("LAUNCH");
        ui->pushButtonLaunch->setFixedWidth(150);
        ui->pushButtonEdit->setEnabled(1);
        ui->pushButtonLoad->setEnabled(1);
        ui->pushButtonSave->setEnabled(1);
        ui->pushButtonNew->setEnabled(1);
        ui->pushButtonPause->hide();
        this->_timer->stop();
    }
}

void MainWindow::on_pushButtonPause_clicked(bool checked){
    _isPaused = !_isPaused;
    if (_isPaused){
        qDebug() << "Simulation has been paused";
        this->setWindowTitle("2d robot simulator [PAUSED]");
        ui->pushButtonPause->setText("PLAY");
        this->_timer->stop();
    } else {
        qDebug() << "Simulation is running";
        this->setWindowTitle("2d robot simulator [RUNNING]");
        ui->pushButtonPause->setText("PAUSE");
        this->_timer->start(FRAME_TIMEGAP_MS);
    }
}

void MainWindow::on_pushButtonLoad_clicked()
{
    _fileToOpen = QFileDialog::getOpenFileName(this, tr("Open JSON File"), QDir::currentPath(), tr("JSON Files (*.json)"));
    QString fileName = QFileInfo(_fileToOpen).fileName();
    if (fileName == ""){
        qDebug() << "There was no file provided for loading";
        QMessageBox::warning(this, "Warning", "There was no file provided for loading");
        return;
    } else{
        ui->labelCurrent->setText("Current Layout: " + fileName);
        qDebug() << "Opening file " << _fileToOpen;
        loadLevel();
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    _fileToSave = QFileDialog::getSaveFileName(this, tr("Save JSON File"), QDir::currentPath(), tr("JSON Files (*.json)"));
    if (!_fileToSave.endsWith(".json") && _fileToSave != "") {
        _fileToSave += ".json";
    }
    QString fileName = QFileInfo(_fileToSave).fileName();
    if (fileName == ""){
        qDebug() << "There was no file provided for saving";
        QMessageBox::warning(this, "Warning", "There was no file provided for saving");
        return;
    } else {
        qDebug() << "Saving file " << _fileToSave;
        string json = _map->SaveJSON();
        QFile file(_fileToSave);
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Failed to open the file\n";
            return;
        }
        file.write(json.c_str());
        file.close();
        ui->labelCurrent->setText("Current Layout: " + fileName);
    }


}

void MainWindow::on_autoRobotIcon_clicked()
{
    ui->viewport->setCursor(Qt::CrossCursor);
    ui->autoRobotIcon->setStyleSheet("border: 2px solid red; padding: 2px;");
    ui->RCRobotIcon->setStyleSheet("");
    ui->obstacleIcon->setStyleSheet("");
    ui->obstacleIcon->setFixedSize(50, 50);
    ui->autoRobotIcon->setFixedSize(75, 75);
    ui->RCRobotIcon->setFixedSize(50, 50);
    _robotIsChosen = true;
    _obstacleIsChosen = _RCRobotIsChosen = false;
    qDebug() << "Click to add <robot> entity.";
}

void MainWindow::on_RCRobotIcon_clicked()
{
    ui->viewport->setCursor(Qt::CrossCursor);
    ui->autoRobotIcon->setStyleSheet("");
    ui->RCRobotIcon->setStyleSheet("border: 2px solid red; padding: 2px;");
    ui->obstacleIcon->setStyleSheet("");
    ui->obstacleIcon->setFixedSize(50, 50);
    ui->autoRobotIcon->setFixedSize(50, 50);
    ui->RCRobotIcon->setFixedSize(75, 75);
    _RCRobotIsChosen = true;
    _robotIsChosen = _obstacleIsChosen = false;
    qDebug() << "Click to add <RCrobot> entity.";
}

void MainWindow::on_obstacleIcon_clicked()
{
    ui->viewport->setCursor(Qt::CrossCursor);
    ui->autoRobotIcon->setStyleSheet("");
    ui->RCRobotIcon->setStyleSheet("");
    ui->obstacleIcon->setStyleSheet("border: 2px solid red; padding: 2px;");
    ui->obstacleIcon->setFixedSize(75, 75);
    ui->autoRobotIcon->setFixedSize(50, 50);
    ui->RCRobotIcon->setFixedSize(50, 50);
    _obstacleIsChosen = true;
    _robotIsChosen = _RCRobotIsChosen = false;
    qDebug() << "Click to add <obstacle> entity.";
}

void MainWindow::on_pushButtonNew_clicked(){
    ui->newMapWidget->show();
}

void MainWindow::on_pushButtonCancel_clicked(){
    ui->newMapWidget->hide();
}

void MainWindow::on_pushButtonConfirm_clicked(){
    ui->newMapWidget->hide();
    int width = ui->widthInput->text().toInt();
    int height = ui->heightInput->text().toInt();
    if (width <= 0 || height <= 0 || width > 10000 || height > 10000){
        qDebug() << "Invalid map size";
        QMessageBox::warning(this, "Warning", "Invalid map size");
        return;
    }
    delete _map;
    _map = new Map(ui->widthInput->text().toInt(), ui->heightInput->text().toInt());
    ui->viewport->drawAll();
    ui->labelCurrent->setText("Current Layout: <none>");
}

bool MainWindow::isObstacleMode()
{
    return _obstacleIsChosen;
}

bool MainWindow::isAutoRobotMode()
{
    return _robotIsChosen;
}

bool MainWindow::isRCRobotMode()
{
    return _RCRobotIsChosen;
}

bool MainWindow::isEditingEnabled()
{
    return _editingEnabled;
}

bool MainWindow::isDefault()
{
    return !_RCRobotIsChosen && !_robotIsChosen && !_obstacleIsChosen;
}

bool MainWindow::isLaunched()
{
    return _isLaunched;
}

void MainWindow::setDefaultEditingState()
{
    ui->autoRobotIcon->setStyleSheet("");
    ui->RCRobotIcon->setStyleSheet("");
    ui->obstacleIcon->setStyleSheet("");
    ui->obstacleIcon->setFixedSize(50, 50);
    ui->autoRobotIcon->setFixedSize(50, 50);
    ui->RCRobotIcon->setFixedSize(50, 50);
    ui->viewport->setCursor(Qt::ArrowCursor);
    qDebug() << "Setting default editing state";
    _obstacleIsChosen = false;
    _robotIsChosen = false;
    _RCRobotIsChosen = false;
}

Map* MainWindow::getMap()
{
    return _map;
}

void MainWindow::RunSimulation() {
    this->_map->Update();
    ui->viewport->Update();
}
