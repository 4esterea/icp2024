#include "RobotWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
#include <QComboBox>


RobotWidget::RobotWidget(QWidget *parent, RobotGraphicItem* robot, bool isRemote) : QWidget(parent), _robot(robot) {
    this->setStyleSheet("background-color: white; color: black;");
    this->setFixedWidth(200);

    QLabel *robotLabel = new QLabel((isRemote ? "RC Robot" : "Auto Robot"), this);
    robotLabel->setAlignment(Qt::AlignCenter);
    robotLabel->setStyleSheet("background-color: gray; color: white;");
    robotLabel->setFixedHeight(25);

    QLabel *angleLabel = new QLabel("Angle", this);
    angleLabel->setAlignment(Qt::AlignCenter);
    angleLabel->setFixedHeight(25);

    QLineEdit *angleInput = new QLineEdit(this);
    angleInput->setStyleSheet("QLineEdit { background-color: white; } QLineEdit:hover { background-color: yellow; } QLineEdit:focus { background-color: white; }");
    angleInput->setAlignment(Qt::AlignCenter);
    angleInput->setValidator(new QIntValidator(0, 360, this));
    angleInput->setText(QString::number(_robot->getGameObject()->GetPosition()->angle));
    angleInput->setFixedHeight(25);

    QLabel *angularSpeedLabel = new QLabel("Angular Speed", this);
    angularSpeedLabel->setAlignment(Qt::AlignCenter);
    angularSpeedLabel->setFixedHeight(25);

    QLineEdit *angularSpeedInput = new QLineEdit(this);
    angularSpeedInput->setAlignment(Qt::AlignCenter);
    angularSpeedInput->setValidator(new QIntValidator(0, 360, this));
    angularSpeedInput->setText(QString::number(_robot->getGameObject()->GetRotationAngle()));
    angularSpeedInput->setFixedHeight(25);

    QLabel *moveSpeedLabel = new QLabel("Move Speed", this);
    moveSpeedLabel->setAlignment(Qt::AlignCenter);
    moveSpeedLabel->setFixedHeight(25);

    QLineEdit *moveSpeedInput = new QLineEdit(this);
    moveSpeedInput->setAlignment(Qt::AlignCenter);
    moveSpeedInput->setValidator(new QIntValidator(0, 1000, this));
    moveSpeedInput->setText(QString::number(_robot->getGameObject()->GetSpeed()));
    moveSpeedInput->setFixedHeight(25);

    QLabel *collisionDistanceLabel = new QLabel("Collision Detection Distance", this);
    collisionDistanceLabel->setAlignment(Qt::AlignCenter);
    collisionDistanceLabel->setFixedHeight(25);

    QLineEdit *collisionDistanceInput = new QLineEdit(this);
    collisionDistanceInput->setAlignment(Qt::AlignCenter);
    collisionDistanceInput->setValidator(new QIntValidator(0, 1000, this));
    //collisionDistanceInput->setText(QString::number(_robot->getCollisionDistance()));
    collisionDistanceInput->setFixedHeight(25);


    QPushButton *okButton = new QPushButton("OK", this);
    okButton->setFixedHeight(25);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(robotLabel);
    layout->addWidget(angleLabel);
    layout->addWidget(angleInput);
    layout->addWidget(angularSpeedLabel);
    layout->addWidget(angularSpeedInput);
    layout->addWidget(moveSpeedLabel);
    layout->addWidget(moveSpeedInput);
    layout->addWidget(collisionDistanceLabel);
    layout->addWidget(collisionDistanceInput);
    if (!isRemote){
        QLabel *evadingBehaviourLabel = new QLabel("Base Evading Behaviour", this);
        evadingBehaviourLabel->setAlignment(Qt::AlignCenter);
        evadingBehaviourLabel->setFixedHeight(25);

        QComboBox *evadingBehaviourInput = new QComboBox(this);
        evadingBehaviourInput->addItem("Move Left");
        evadingBehaviourInput->addItem("Move Right");
        //evadingBehaviourInput->setCurrentText(_robot->getEvadingBehaviour());
        evadingBehaviourInput->setFixedHeight(25);

        layout->addWidget(evadingBehaviourLabel);
        layout->addWidget(evadingBehaviourInput);

        connect(evadingBehaviourInput, &QComboBox::currentTextChanged, [this](const QString &value) {
        // TODO
    });
    }

    layout->addWidget(okButton);

    this->setLayout(layout);

    connect(angleInput, &QLineEdit::textChanged, [this](const QString &value) {
        _robot->setRotation(value.toInt());
    });

    connect(angularSpeedInput, &QLineEdit::textChanged, [this](const QString &value) {
        _robot->getGameObject()->SetRotationAngle(value.toInt());
    });

    connect(moveSpeedInput, &QLineEdit::textChanged, [this](const QString &value) {
        _robot->getGameObject()->SetSpeed(value.toInt());
    });

    connect(collisionDistanceInput, &QLineEdit::textChanged, [this](const QString &value) {
        // TODO
    });



    connect(okButton, &QPushButton::clicked, this, &RobotWidget::hide);
}
