#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "level.h"

class GameWindow : public QGraphicsView
{
private:
    Level *levelOne;

public:
    GameWindow();

    void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEWINDOW_H
