#include "player.h"

Player::Player(const int &x, const int &y, Direction d, QObject *parent)
    : QObject{parent}, posX(x), posY(y), direction(d)
{
    container = new QGraphicsRectItem(0, 0, WH_PLAYER-1, WH_PLAYER-1); container->setPen(QColor(255,0,0));
    stomach = new QGraphicsRectItem(0, 0, 3, 3);

    sprite = new QPixmap();
    currentFrame = 0;

    this->updatePos();
    this->changeSprite();
}

int Player::getPosX() const
{
    return posX;
}

int Player::getPosY() const
{
    return posY;
}

void Player::newPos(const int &x, const int &y)
{
    posX = x;
    posY = y;
    this->updatePos();
}

Direction Player::getDirection() const
{
    return direction;
}

void Player::updatePos()
{
    container->setPos(posX, posY);
    stomach->setPos(posX+6, posY+6);
    this->setPos(posX, posY);
    this->nextFrame();
}

void Player::changeSprite()
{
    if(direction == Direction::Up){ *sprite = QPixmap(":/images/up.png"); }
    else if(direction == Direction::Down){ *sprite = QPixmap(":/images/down.png"); }
    else if(direction == Direction::Left){ *sprite = QPixmap(":/images/left.png"); }
    else if(direction == Direction::Right){ *sprite = QPixmap(":/images/right.png"); }
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
    return this->collidesWithItem(wall);
}

bool Player::collidingWithPill(const Pill *pill)
{
    return stomach->collidesWithItem(pill);
}

void Player::setDirection(Direction newDirection)
{
    direction = newDirection;
    this->changeSprite();
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
    currentFrame = 16;
    this->updatePos();
}

void Player::nextFrame()
{
    if(direction != Direction::None){ currentFrame += WH_PLAYER; }
    if(currentFrame >= WH_PLAYER * 4){ currentFrame = 0; }
    this->update(0, 0, WH_PLAYER, WH_PLAYER);
}

QRectF Player::boundingRect() const
{
    return QRectF(-0.5, -0.5, WH_PLAYER, WH_PLAYER);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *sprite, currentFrame, 0, WH_PLAYER, WH_PLAYER);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
