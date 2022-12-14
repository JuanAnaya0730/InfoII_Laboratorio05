#include "level.h"
#include <fstream>

#include <QDebug>

Level::Level(const QString &fileName, QObject *parent) :
    QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, WH_WALL*29, WH_WALL*36);
    this->loadLevel(fileName);

    /* Aqui se inicializan los atributos */
    pacman = new Player(WH_WALL*17, WH_WALL*17);
    score = new Score(0, WH_WALL*32);
    timer = new Timer(WH_WALL*22, WH_WALL*32);
    autoMove = new QTimer();
    futureDirection = Direction::Left;

    msgBox.setWindowTitle("Juego terminado");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    /* Aqui se añaden los graficos */
    this->setBackgroundBrush(QColor(0,0,0));
    this->addPixmap(QPixmap(":/images/maze.png"));
    for(int i=0; i < food.size(); ++i){ this->addItem(food[i]); }
    this->addItem(pacman);
    this->addWidget(score);
    this->addWidget(timer);

    connect(timer, &Timer::ended, this, &Level::gameOver);
    connect(autoMove, &QTimer::timeout, this, &Level::movePlayer);

    timer->start();
    autoMove->start(20);
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

    if(pacman->getPosX() < -WH_PLAYER){ pacman->newPos(WH_WALL*29, pacman->getPosY()); }
    else if(pacman->getPosX() > WH_WALL*29){ pacman->newPos(-WH_PLAYER, pacman->getPosY()); };

    for(int i=0; i < food.size(); ++i){
        if(pacman->collidingWithPill(food[i])){
            this->removeItem(food[i]);
            food.removeAt(i);
            score->increase();
            if(food.isEmpty()){ this->gameWon(); }
        }
    }

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

void Level::gameWon()
{
    autoMove->stop();
    timer->stop();
    msgBox.setText("¡Ganaste wacho!\nTiempo final: " + QString::number(60-(timer->getTime().toString("ss")).toInt()));
    if (QMessageBox::Ok == msgBox.exec()){
        exit(1);
    }
}

void Level::gameOver()
{
    autoMove->stop();
    msgBox.setText("¡Perdiste! Pai eres un poquito manco\nPuntaje final: " + QString::number(score->getScore()));
    if (QMessageBox::Ok == msgBox.exec()){
        exit(1);
    }
}
