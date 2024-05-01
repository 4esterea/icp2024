#include "ObstacleWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>

ObstacleWidget::ObstacleWidget(QWidget *parent, HoverableObstacle* obstacle) : QWidget(parent) {
    this->_obstacle = obstacle;
    this->setStyleSheet("background-color: white;"); // Set the background color to white
    this->setFixedWidth(200);
    QLabel *obstacleLabel = new QLabel("Obstacle", this);
    obstacleLabel->setAlignment(Qt::AlignCenter); // Center the label
    obstacleLabel->setStyleSheet("background-color: gray;");
    obstacleLabel->setFixedHeight(30); // Set maximum height for the label

    QLabel *rotationLabel = new QLabel("Rotation (°)", this);
    rotationLabel->setAlignment(Qt::AlignCenter); // Center the label
    rotationLabel->setFixedHeight(30); // Set maximum height for the label

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

    QPushButton *okButton = new QPushButton("OK", this); // Initialize QPushButton object
    okButton->setFixedHeight(30);

    QVBoxLayout *layout = new QVBoxLayout(this); // Create a new vertical box layout
    layout->setSpacing(0); // Remove spacing between widgets
    layout->setContentsMargins(0, 0, 0, 0); // Remove margins
    layout->addWidget(obstacleLabel); // Add the obstacle label to the layout
    layout->addWidget(rotationLabel); // Add the rotation label to the layout // Add the rotation slider to the layout
    layout->addWidget(rotationInput); // Add the rotation value to the layout
    layout->addWidget(widthLabel);
    layout->addWidget(widthInput);
    layout->addWidget(heightLabel);
    layout->addWidget(heightInput);
    layout->addWidget(okButton); // Add the OK button to the layout

    this->setLayout(layout); // Set the layout of the widget


    connect(rotationInput, &QLineEdit::textChanged, [this](const QString &value) {
    int rotationValue = value.toInt();
    this->_obstacle->setRotation(rotationValue);
    });

    connect(widthInput, &QLineEdit::textChanged, [this](const QString &value) {
    QRectF rect = this->_obstacle->rect();
    rect.setWidth(value.toInt());
    this->_obstacle->setRect(rect);
    this->_obstacle->setTransformOriginPoint(rect.width() / 2, rect.height() / 2);
    });

    connect(heightInput, &QLineEdit::textChanged, [this](const QString &value) {
        QRectF rect = this->_obstacle->rect();
        rect.setHeight(value.toInt());
        this->_obstacle->setRect(rect);
        this->_obstacle->setTransformOriginPoint(rect.width() / 2, rect.height() / 2);
    });



    connect(okButton, &QPushButton::clicked, this, &ObstacleWidget::hide);
}
