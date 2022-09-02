#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QString>
#include <QList>
#include <QTimer>
#include "wall.h"
#include "pill.h"
#include "player.h"

class Level : public QGraphicsScene
{
    Q_OBJECT
private:
    Player *pacman;
    QList<Wall *> maze;
    QList<Pill *> food;

    QTimer *autoMove;
    Direction futureDirection;

    void loadLevel(const QString &fileName);

public:
    explicit Level(const QString &fileName, QObject *parent = nullptr);

    void setPlayerDirection(Direction newDirection);

public slots:
    void movePlayer();
};

#endif // LEVEL_H
