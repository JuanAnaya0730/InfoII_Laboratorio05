#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QPainter>
#include "wall.h"
#include "pill.h"

#define WH_PLAYER 16 // Ancho y alto para el contorno del personaje
#define VEL 2

enum class Direction{None, Up, Down, Left, Right}; // Direccion en la que se movera el personaje

class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int posX;
    int posY;
    Direction direction;
    QGraphicsRectItem *container;
    QGraphicsRectItem *stomach;

    QPixmap *sprite;
    int currentFrame;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void updatePos();
    void changeSprite();

public:
    explicit Player(const int &x, const int &y, Direction d = Direction::None, QObject *parent = nullptr);

    int getPosX() const;
    int getPosY() const;
    void newPos(const int &x, const int &y);
    Direction getDirection() const;
    QGraphicsRectItem *getContainer() const;
    QGraphicsRectItem *getStomach() const;
    bool collidingWithWall(const Wall *wall);
    bool collidingWithPill(const Pill *pill);
    void setDirection(Direction newDirection);
    void move();
    void moveBack();

    void nextFrame();
};

#endif // PLAYER_H
