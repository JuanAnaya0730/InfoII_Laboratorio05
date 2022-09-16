#include "wall.h"

Wall::Wall(const int &x, const int &y)
{
    this->setPos(x, y);
}

QRectF Wall::boundingRect() const
{
    return QRectF(-0.5, -0.5, WH_WALL, WH_WALL);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(0,0,255));
    painter->drawRect(0, 0, WH_WALL-1, WH_WALL-1);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
