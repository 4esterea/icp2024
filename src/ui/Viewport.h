#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsView>
#include <QPainter>
#include "src/headers/Map.h"

class Viewport : public QGraphicsView {
public:
    Viewport(QWidget* parent = nullptr, Map* map = nullptr);
    void setMap(Map* map);
    void drawAll();
    void mousePressEvent(QMouseEvent *event) override;
    void hideAllSettings();
	QGraphicsScene* scene;
private:
    Map* _map;
};

#endif // VIEWPORT_H
