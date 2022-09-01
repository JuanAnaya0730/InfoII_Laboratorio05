#ifndef PILL_H
#define PILL_H

#include <QGraphicsItem>
#include <QPainter>

#define WH_PILL 2 // Ancho y alto de la pildora

class Pill : public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public:
    Pill();
};

#endif // PILL_H
