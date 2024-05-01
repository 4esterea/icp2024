#include "mainwindow.h"
#include "ui/clickableLabel.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QFile>
#include <QIODevice>
#include <QPixmap>
#include "ui/Viewport.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUiDefaultState();

    QFile file("lvl/lvl1.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open the file\n";
        return;
    }
    std::string json = file.readAll().toStdString();
    Map *map = new Map(0, 0);
    map->LoadJSON(json);

    ui->viewport->setMap(map);
    ui->viewport->setRenderHint(QPainter::Antialiasing);
    ui->viewport->drawAll();
}

void MainWindow::setUiDefaultState()
{
    ui->labelCurrent->setText("Current Layout: <none>");
    ui->comboBox->clear();
    ui->comboBox->addItem("Turn Left");
    ui->comboBox->addItem("Turn Right");
    ui->pushButtonEdit->setText("EDIT");
    ui->pushButtonLaunch->setText("LAUNCH");
    ui->pushButtonPause->setText("PAUSE");
    ui->pushButtonLaunch->setFixedWidth(150);
    ui->pushButtonPause->setFixedWidth(70);
    ui->pushButtonPause->hide();
    _editingEnabled = false;
    _isLaunched = false;
    _isPaused = false;
    _turnRight = false;
    _robotIsChosen = _RCRobotIsChosen = _obstacleIsChosen = false;
    QPixmap pm("C:/Users/USer/Downloads/circlePlaceholder.png");
    ui->autoRobotIcon->setPixmap(pm);
    ui->autoRobotIcon->setScaledContents(true);
    ui->autoRobotIcon->setFixedSize(140, 140);
    ui->RCRobotIcon->setPixmap(pm);
    ui->RCRobotIcon->setScaledContents(true);
    ui->RCRobotIcon->setFixedSize(140, 140);
    ui->obstacleIcon->setPixmap(pm);
    ui->obstacleIcon->setScaledContents(true);
    ui->obstacleIcon->setFixedSize(140, 140);
    ui->editMode->hide();
    connect(ui->doubleSpinBoxRMS, SIGNAL(valueChanged(double)), this, SLOT(updateRobotMoveSpeed(double)));
    connect(ui->doubleSpinBoxRAS, SIGNAL(valueChanged(double)), this, SLOT(updateRobotAngularSpeed(double)));
    connect(ui->doubleSpinBoxCDD, SIGNAL(valueChanged(double)), this, SLOT(updateCollisionDetectionDistance(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        qDebug() << "Turn Left option has been chosen";
        _turnRight = false;
        break;
    case 1:
        qDebug() << "Turn Right option has been chosen";
        _turnRight = true;
        break;
    }
}

void MainWindow::on_pushButtonEdit_clicked(bool checked)
{
    _editingEnabled = !_editingEnabled;
    _robotIsChosen = _RCRobotIsChosen = _obstacleIsChosen = false;
    if (_editingEnabled){
        qDebug() << "Editing is Enabled";
        ui->pushButtonEdit->setText("STOP EDITING");
        ui->pushButtonLaunch->setEnabled(0);
        ui->widgetSettings->hide();
        ui->editMode->show();
    } else {
        ui->pushButtonEdit->setText("EDIT");
        qDebug() << "Editing is Disabled";
        ui->pushButtonLaunch->setEnabled(1);
        ui->widgetSettings->show();
        ui->editMode->hide();
    }
}

void MainWindow::on_pushButtonLaunch_clicked(bool checked)
{
    _isLaunched = !_isLaunched;
    if (_isLaunched){
        qDebug() << "Simulation is running";
        ui->pushButtonLaunch->setText("STOP");
        ui->pushButtonLaunch->setFixedWidth(70);
        ui->pushButtonEdit->setEnabled(0);
        ui->pushButtonLoad->setEnabled(0);
        ui->pushButtonSave->setEnabled(0);
        ui->doubleSpinBoxRMS->setEnabled(0);
        ui->doubleSpinBoxRAS->setEnabled(0);
        ui->doubleSpinBoxCDD->setEnabled(0);
        ui->comboBox->setEnabled(0);
        ui->pushButtonPause->show();
    } else {
        qDebug() << "Simulation has been stopped";
        ui->pushButtonLaunch->setText("LAUNCH");
        ui->pushButtonLaunch->setFixedWidth(150);
        ui->pushButtonEdit->setEnabled(1);
        ui->pushButtonLoad->setEnabled(1);
        ui->pushButtonSave->setEnabled(1);
        ui->doubleSpinBoxRMS->setEnabled(1);
        ui->doubleSpinBoxRAS->setEnabled(1);
        ui->doubleSpinBoxCDD->setEnabled(1);
        ui->comboBox->setEnabled(1);
        ui->pushButtonPause->hide();
    }
}

void MainWindow::on_pushButtonPause_clicked(bool checked){
    _isPaused = !_isPaused;
    if (_isPaused){
        qDebug() << "Simulation has been paused";
        ui->pushButtonPause->setText("PLAY");
    } else {
        qDebug() << "Simulation is running";
        ui->pushButtonPause->setText("PAUSE");
    }
}

void MainWindow::on_pushButtonLoad_clicked()
{
    _fileToOpen = QFileDialog::getOpenFileName(this, tr("Open JSON File"), QDir::homePath(), tr("JSON Files (*.json)"));
    QString fileName = QFileInfo(_fileToOpen).fileName();
    if (fileName == ""){
        ui->labelCurrent->setText("Current Layout: <none>");
        qDebug() << "There was no file provided for loading";
    } else{
        ui->labelCurrent->setText("Current Layout: " + fileName);
        qDebug() << "Opening file " << _fileToOpen;
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    _fileToSave = QFileDialog::getSaveFileName(this, tr("Save JSON File"), QDir::homePath(), tr("JSON Files (*.json)"));
    QString fileName = QFileInfo(_fileToSave).fileName();
    if (fileName == ""){
        qDebug() << "There was no file provided for saving";
    } else {
        qDebug() << "Saving file " << _fileToSave;
    }

}

void MainWindow::on_autoRobotIcon_clicked()
{
    _robotIsChosen = true;
    _obstacleIsChosen = _RCRobotIsChosen = false;
    qDebug() << "Click to add <robot> entity.";
}

void MainWindow::on_RCRobotIcon_clicked()
{
    _RCRobotIsChosen = true;
    _robotIsChosen = _obstacleIsChosen = false;
    qDebug() << "Click to add <RCrobot> entity.";
}

void MainWindow::on_obstacleIcon_clicked()
{
    _obstacleIsChosen = true;
    _robotIsChosen = _RCRobotIsChosen = false;
    qDebug() << "Click to add <obstacle> entity.";
}

void MainWindow::updateRobotMoveSpeed(double value) {
    qDebug() << "RMS is " << value;
    _robotMoveSpeed = value;
}

void MainWindow::updateRobotAngularSpeed(double value) {
    qDebug() << "RAS is " << value;
    _robotAngularSpeed = value;
}

void MainWindow::updateCollisionDetectionDistance(double value) {
    qDebug() << "CDD is " << value;
    _collisionDetectionDistance = value;
}
