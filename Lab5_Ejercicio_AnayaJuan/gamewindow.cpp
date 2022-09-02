#include "gamewindow.h"

GameWindow::GameWindow()
{
    levelOne = new Level("Level1.txt", this);
    this->setScene(levelOne);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        levelOne->setPlayerDirection(Direction::Up);
        break;
    case Qt::Key_Down:
        levelOne->setPlayerDirection(Direction::Down);
        break;
    case Qt::Key_Left:
        levelOne->setPlayerDirection(Direction::Left);
        break;
    case Qt::Key_Right:
        levelOne->setPlayerDirection(Direction::Right);
        break;
    }
}
