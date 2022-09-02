#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

#define WH_PLAYER 16 // Ancho y alto para el contorno del personaje

class Player : public QObject
{
    Q_OBJECT
private:
    QGraphicsRectItem *container;

public:
    explicit Player(QObject *parent = nullptr);

signals:

};

#endif // PLAYER_H
