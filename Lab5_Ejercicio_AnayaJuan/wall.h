#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>
#include <QPainter>

#define WH_WALL 8 // Ancho y alto del muro

class Wall : public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public:
    Wall(const int &x, const int &y);
};

#endif // WALL_H
