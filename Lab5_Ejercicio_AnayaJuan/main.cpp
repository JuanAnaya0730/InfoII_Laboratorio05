#include "gamewindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon.png"));
    QCoreApplication::setApplicationName("Pacman");
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/welcome.png"));
    splash->show();

    GameWindow gw;

    QTimer::singleShot(3000,splash, &QSplashScreen::close);
    QTimer::singleShot(3100,&gw, &GameWindow::show);

    return a.exec();
}
