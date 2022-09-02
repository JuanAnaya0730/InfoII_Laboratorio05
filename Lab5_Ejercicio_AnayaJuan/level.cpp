#include "level.h"
#include <fstream>

#include <QDebug>

Level::Level(const QString &fileName, QObject *parent) :
    QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, WH_WALL*29, WH_WALL*32);
    this->loadLevel(fileName);

    /* Aqui se inicializan los atributos */
    pacman = new Player(WH_WALL*14, WH_WALL*17);
    autoMove = new QTimer();
    futureDirection = Direction::Left;

    /* Aqui se añaden los muros pacman y las pildora a la escena */
    for(int i=0; i < maze.size(); ++i){ this->addItem(maze[i]); }
    for(int i=0; i < food.size(); ++i){ this->addItem(food[i]); }
    this->addItem(pacman->getContainer());
    //this->addItem(pacman);

    connect(autoMove, &QTimer::timeout, this, &Level::movePlayer);
    autoMove->start(40);
}

void Level::loadLevel(const QString &fileName)
{
    std::ifstream file;
    std::string line;
    QList<std::string> textMap;

    file.open("../Lab5_Ejercicio_AnayaJuan/levels/" + fileName.toStdString());
    if(!file.is_open()){ qDebug() << "efectivamente mi compai"; }
    while(!file.eof()){
        std::getline(file, line);
        textMap.append(line);
    }
    file.close();

    for(int i=0; i < textMap.size(); ++i){
        for(int j=0; j < (int)textMap[i].length(); ++j){
            if(textMap[i][j] == 'X'){ this->maze.append(new Wall(j*WH_WALL, i*WH_WALL)); }
            else if(textMap[i][j] == '.'){ this->food.append(new Pill(j*WH_WALL-1, i*WH_WALL-1)); }
        }
    }
}

bool Level::canPlayerChangeDirection()
{
    Player temp(pacman->getPosX(), pacman->getPosY(), futureDirection);
    temp.move();
    for(int i=0; i < maze.size(); ++i){
        if(temp.collidingWithWall(maze[i])){ return false; }
    }
    return true;
}

void Level::setPlayerDirection(Direction newDirection)
{
    futureDirection = newDirection;
}

void Level::movePlayer()
{
    pacman->move();
    if(futureDirection != pacman->getDirection() && canPlayerChangeDirection()){
        pacman->setDirection(futureDirection);
    }

    for(int i=0; i < maze.size(); ++i){
        if(pacman->collidingWithWall(maze[i])){
            pacman->moveBack();
            break;
        }
    }
}
