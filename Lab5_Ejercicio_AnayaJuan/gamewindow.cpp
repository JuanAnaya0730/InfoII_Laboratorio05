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
        break;
    case Qt::Key_Down:
        break;
    case Qt::Key_Left:
        break;
    case Qt::Key_Right:
        break;
    }
}
