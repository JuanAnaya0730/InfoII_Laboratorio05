#include "gamewindow.h"

GameWindow::GameWindow()
{
    levelOne = new Level("Level1.txt", this);
    this->setScene(levelOne);
}
