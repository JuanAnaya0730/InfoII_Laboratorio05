#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{
    container = new QGraphicsRectItem(0, 0, WH_PLAYER-1, WH_PLAYER-1);
}

QGraphicsRectItem *Player::getContainer() const
{
    return container;
}
