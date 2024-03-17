#include "mainwindow.h"
#include "ui_mainwindow.h"
#

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    ui->comboBox->addItem("Turn Left");
    ui->comboBox->addItem("Turn Right");
    ui->pushButton->setText("EDIT");
    editingEnabled = false;
    connect(ui->comboBox, SIGNAL(activated()), this, SLOT(on_comboBox_activated()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        qDebug() << "Turn Left option had been chosen";
        break;
    case 1:
        qDebug() << "Turn Right option had been chosen";
        break;
    }
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    editingEnabled = !editingEnabled;
    if (editingEnabled){
        qDebug() << "Editing is Enabled";
        ui->pushButton->setText("STOP EDITING");
    } else {
        ui->pushButton->setText("EDIT");
        qDebug() << "Editing is Disabled";
    }
}

