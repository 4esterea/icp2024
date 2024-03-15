#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    if (_editingEnabled){
        qDebug() << "Editing is Enabled";
        ui->pushButtonEdit->setText("STOP EDITING");
        ui->pushButtonLaunch->setEnabled(0);
        ui->labelSettings->parentWidget()->hide();
    } else {
        ui->pushButtonEdit->setText("EDIT");
        qDebug() << "Editing is Disabled";
        ui->pushButtonLaunch->setEnabled(1);
        ui->labelSettings->parentWidget()->show();
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
    } else{
        ui->labelCurrent->setText("Current Layout: " + fileName);
    }
    qDebug() << "Opening file " << _fileToOpen;
}

void MainWindow::on_pushButtonSave_clicked()
{
    _fileToSave = QFileDialog::getSaveFileName(this, tr("Save JSON File"), QDir::homePath(), tr("JSON Files (*.json)"));
    qDebug() << "Saving file " << _fileToSave;
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
