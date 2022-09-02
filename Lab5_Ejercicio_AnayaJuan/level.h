#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QString>
#include <QList>
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

    void loadLevel(const QString &fileName);

public:
    explicit Level(const QString &fileName, QObject *parent = nullptr);
};

#endif // LEVEL_H
