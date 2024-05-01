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
    QGraphicsScene* scene;
private:
    Map* _map;
    QVector<QGraphicsItem*> _objects;
};

#endif // VIEWPORT_H
