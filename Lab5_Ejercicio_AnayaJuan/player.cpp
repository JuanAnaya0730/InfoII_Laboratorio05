#include "player.h"

Player::Player(const int &x, const int &y, Direction d, QObject *parent)
    : QObject{parent}, posX(x), posY(y), direction(d)
{
    container = new QGraphicsRectItem(0, 0, WH_PLAYER-1, WH_PLAYER-1);
    container->setPos(posX, posY);
}

void Player::updatePos()
{
    if(direction == Direction::Up){ posY -= VEL; }
    else if(direction == Direction::Down){ posY += VEL; }
    else if(direction == Direction::Left){ posX -= VEL; }
    else if(direction == Direction::Right){ posX += VEL; }
}

QGraphicsRectItem *Player::getContainer() const
{
    return container;
}

void Player::setDirection(Direction newDirection)
{
    direction = newDirection;
}

void Player::move()
{
    this->updatePos();

    container->setPos(posX, posY);
}
