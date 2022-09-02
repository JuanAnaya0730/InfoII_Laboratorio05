#include "player.h"

Player::Player(const int &x, const int &y, Direction d, QObject *parent)
    : QObject{parent}, posX(x), posY(y), direction(d)
{
    container = new QGraphicsRectItem(0, 0, WH_PLAYER-1, WH_PLAYER-1);
    stomach = new QGraphicsRectItem(0, 0, 3, 3);

    this->updatePos();
}

int Player::getPosX() const
{
    return posX;
}

int Player::getPosY() const
{
    return posY;
}

Direction Player::getDirection() const
{
    return direction;
}

void Player::updatePos()
{
    container->setPos(posX, posY);
    stomach->setPos(posX+6, posY+6);
}

QGraphicsRectItem *Player::getContainer() const
{
    return container;
}

QGraphicsRectItem *Player::getStomach() const
{
    return stomach;
}

bool Player::collidingWithWall(const Wall *wall)
{
    return container->collidesWithItem(wall);
}

bool Player::collidingWithPill(const Pill *pill)
{
    return stomach->collidesWithItem(pill);
}

void Player::setDirection(Direction newDirection)
{
    direction = newDirection;
}

void Player::move()
{
    if(direction == Direction::Up){ posY -= VEL; }
    else if(direction == Direction::Down){ posY += VEL; }
    else if(direction == Direction::Left){ posX -= VEL; }
    else if(direction == Direction::Right){ posX += VEL; }

    this->updatePos();
}

void Player::moveBack()
{
    if(direction == Direction::Up){ posY += VEL; }
    else if(direction == Direction::Down){ posY -= VEL; }
    else if(direction == Direction::Left){ posX += VEL; }
    else if(direction == Direction::Right){ posX -= VEL; }

    direction = Direction::None;
    this->updatePos();
}
