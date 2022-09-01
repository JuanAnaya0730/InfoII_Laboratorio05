#include "pill.h"

Pill::Pill(const int &x, const int &y)
{
    this->setPos(x, y);
}

QRectF Pill::boundingRect() const
{
    return QRectF(-0.5, -0.5, WH_PILL, WH_PILL);
}

void Pill::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(0, 0, WH_PILL-1, WH_PILL-1);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
