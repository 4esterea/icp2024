#include "ObstacleWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>



ObstacleWidget::ObstacleWidget(QWidget *parent, ObstacleGraphicItem* obstacle) : QWidget(parent) {
    this->_obstacle = obstacle;
    this->setStyleSheet("background-color: white;");
    this->setFixedWidth(200);
    QLabel *obstacleLabel = new QLabel("Obstacle", this);
    obstacleLabel->setAlignment(Qt::AlignCenter);
    obstacleLabel->setStyleSheet("background-color: gray;");
    obstacleLabel->setFixedHeight(30);

    QLabel *rotationLabel = new QLabel("Rotation (°)", this);
    rotationLabel->setAlignment(Qt::AlignCenter);
    rotationLabel->setFixedHeight(30);

    QLineEdit *rotationInput = new QLineEdit(this);
    rotationInput->setAlignment(Qt::AlignCenter);
    rotationInput->setValidator(new QIntValidator(0, 360, this));
    rotationInput->setText(QString::number(this->_obstacle->rotation()));
    rotationInput->setFixedHeight(30);

    QLabel *widthLabel = new QLabel("Width", this);
    widthLabel->setAlignment(Qt::AlignCenter);
    widthLabel->setFixedHeight(30);

    QLineEdit *widthInput = new QLineEdit(this);
    widthInput->setValidator(new QIntValidator(1, 1000, this));
    widthInput->setText(QString::number(this->_obstacle->rect().width()));
    widthInput->setAlignment(Qt::AlignCenter);
    widthInput->setFixedHeight(30);

    QLabel *heightLabel = new QLabel("Height", this);
    heightLabel->setAlignment(Qt::AlignCenter);
    heightLabel->setFixedHeight(30);

    QLineEdit *heightInput = new QLineEdit(this);
    heightInput->setAlignment(Qt::AlignCenter);
    heightInput->setValidator(new QIntValidator(1, 700, this));
    heightInput->setText(QString::number(this->_obstacle->rect().height()));
    heightInput->setFixedHeight(30);

    QPushButton *okButton = new QPushButton("OK", this);
    okButton->setFixedHeight(30);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(obstacleLabel);
    layout->addWidget(rotationLabel);
    layout->addWidget(rotationInput);
    layout->addWidget(widthLabel);
    layout->addWidget(widthInput);
    layout->addWidget(heightLabel);
    layout->addWidget(heightInput);
    layout->addWidget(okButton);

    this->setLayout(layout);


    connect(rotationInput, &QLineEdit::textChanged, [this](const QString &value) {
        this->_obstacle->setRotation(value.toInt());
    });

    connect(widthInput, &QLineEdit::textChanged, [this](const QString &value) {
        this->_obstacle->setWidth(value.toInt());
    });

    connect(heightInput, &QLineEdit::textChanged, [this](const QString &value) {
        this->_obstacle->setHeight(value.toInt());
    });



    connect(okButton, &QPushButton::clicked, this, &ObstacleWidget::hide);
}
