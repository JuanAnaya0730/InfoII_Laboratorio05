#include "player.h"

Player::Player(const int &x, const int &y, QObject *parent)
    : QObject{parent}, posX(x), posY(y)
{
    container = new QGraphicsRectItem(0, 0, WH_PLAYER-1, WH_PLAYER-1);
    container->setPos(posX, posY);
}

QGraphicsRectItem *Player::getContainer() const
{
    return container;
}
