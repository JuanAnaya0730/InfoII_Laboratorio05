#include "gamewindow.h"

GameWindow::GameWindow()
{
    levelOne = new Level(this);
    this->setScene(levelOne);
}
