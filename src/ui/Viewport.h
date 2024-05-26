/**
* @file Viewport.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 01.05.2024
 * @brief Declaration of Viewport
 */

#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsView>
#include <QPainter>
#include "src/headers/Map.h"
#include <QMessageBox>

class MainWindow;

/**
 * @class Viewport
 * @brief This class represents the viewport in the application.
 *
 * The Viewport class extends QGraphicsView and provides functionalities for handling
 * different events and managing the graphical representation of the application.
 */
class Viewport : public QGraphicsView {
public:
    /**
     * @brief Constructor for Viewport class.
     *
     * @param parent The parent QWidget object.
     * @param map The Map object.
     */
    Viewport(QWidget* parent = nullptr, Map* map = nullptr);

    /**
     * @brief Draws all elements in the viewport.
     */
    void drawAll();

    /**
     * @brief Updates the viewport.
     */
    void Update();

    /**
     * @brief Event handler for mouse press event.
     *
     * @param event The QMouseEvent object.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Hides all settings in the viewport.
     */
    void hideAllSettings();

    /**
    * @brief A pointer to the QGraphicsScene object.
    */
	   QGraphicsScene* scene;

    /**
     * @brief Checks if a remote-controlled robot is placed in the viewport.
     *
     * @return True if the robot is placed, false otherwise.
     */
    bool isRCRobotPlaced();

    /**
     * @brief Removes the remote-controlled robot from the viewport.
     */
    void removeRC();

protected:
     /**
    * @brief Event handler for wheel event.
    *
    * @param event The QWheelEvent object.
    */
    void wheelEvent(QWheelEvent *event) override;
    /**
     * @brief Handles the key press events in the Viewport.
     *
     * @param event The QKeyEvent object representing the key press event.
     */
    void keyPressEvent(QKeyEvent *event) override;
private:
    MainWindow* _mainWindow;
    Map* _map;
    bool _isRCRobotPlaced = false;
};

#endif // VIEWPORT_H
