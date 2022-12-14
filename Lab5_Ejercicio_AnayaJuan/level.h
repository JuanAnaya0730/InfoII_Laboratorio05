#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QTimer>
#include "wall.h"
#include "pill.h"
#include "player.h"
#include "score.h"
#include "timer.h"

class Level : public QGraphicsScene
{
    Q_OBJECT
private:
    Player *pacman;
    Score *score;
    Timer *timer;
    QList<Wall *> maze;
    QList<Pill *> food;

    QTimer *autoMove;
    Direction futureDirection;

    QMessageBox msgBox;

    void loadLevel(const QString &fileName);
    bool canPlayerChangeDirection();
    void gameWon();

public:
    explicit Level(const QString &fileName, QObject *parent = nullptr);

    void setPlayerDirection(Direction newDirection);

public slots:
    void movePlayer();
    void gameOver();
};

#endif // LEVEL_H
