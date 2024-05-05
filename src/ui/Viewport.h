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

class Viewport : public QGraphicsView {
public:
    Viewport(QWidget* parent = nullptr, Map* map = nullptr);
    void drawAll();
    void Update();
    void mousePressEvent(QMouseEvent *event) override;
    void hideAllSettings();
	QGraphicsScene* scene;
protected:
    void wheelEvent(QWheelEvent *event) override;
private:
    Map* _map;
    bool _isRCRobotPlaced = false;
};

#endif // VIEWPORT_H
