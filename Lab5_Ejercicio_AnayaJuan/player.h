#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include "wall.h"

#define WH_PLAYER 16 // Ancho y alto para el contorno del personaje
#define VEL 2

enum class Direction{None, Up, Down, Left, Right}; // Direccion en la que se movera el personaje

class Player : public QObject
{
    Q_OBJECT
private:
    int posX;
    int posY;
    Direction direction;
    QGraphicsRectItem *container;

    void updatePos();

public:
    explicit Player(const int &x, const int &y, Direction d = Direction::None, QObject *parent = nullptr);

    int getPosX() const;
    int getPosY() const;
    Direction getDirection() const;
    QGraphicsRectItem *getContainer() const;
    bool collidingWithWall(const Wall *wall);
    void setDirection(Direction newDirection);
    void move();
    void moveBack();
};

#endif // PLAYER_H
