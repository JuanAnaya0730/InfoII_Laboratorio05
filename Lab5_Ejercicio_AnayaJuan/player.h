#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

#define WH_PLAYER 16 // Ancho y alto para el contorno del personaje
#define VEL 1

enum Direction{None, Up, Down, Left, Right}; // Direccion en la que se movera el personaje

class Player : public QObject
{
    Q_OBJECT
private:
    int posX;
    int posY;
    Direction direction;
    QGraphicsRectItem *container;

public:
    explicit Player(const int &x, const int &y, Direction d, QObject *parent = nullptr);

    QGraphicsRectItem *getContainer() const;
    void setDirection(Direction newDirection);
    void move();

signals:

};

#endif // PLAYER_H
