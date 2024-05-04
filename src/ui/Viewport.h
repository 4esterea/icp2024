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
private:
    Map* _map;
    bool _isRCRobotPlaced = false;
};

#endif // VIEWPORT_H
