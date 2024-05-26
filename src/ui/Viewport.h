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

    bool isRCRobotPlaced();

    void removeRC();
protected:
     /**
    * @brief Event handler for wheel event.
    *
    * @param event The QWheelEvent object.
    */
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    MainWindow* _mainWindow;
    Map* _map;
    bool _isRCRobotPlaced = false;
};

#endif // VIEWPORT_H
