#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

#define WH_PLAYER 16 // Ancho y alto para el contorno del personaje

class Player : public QObject
{
    Q_OBJECT
private:
    int posX;
    int posY;
    QGraphicsRectItem *container;

public:
    explicit Player(const int &x, const int &y, QObject *parent = nullptr);

    QGraphicsRectItem *getContainer() const;

signals:

};

#endif // PLAYER_H
