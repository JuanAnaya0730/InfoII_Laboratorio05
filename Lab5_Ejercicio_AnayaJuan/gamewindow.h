#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include "level.h"

class GameWindow : public QGraphicsView
{
private:
    Level *levelOne;

public:
    GameWindow();
};

#endif // GAMEWINDOW_H
