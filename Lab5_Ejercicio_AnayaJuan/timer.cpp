#include "timer.h"

void Timer::updateText()
{
    this->setText("TIME\n" + time.toString("m:ss"));
}

Timer::Timer(const int &x, const int &y)
{
    time = QTime(0,1,0);
    timer = new QTimer();

    this->setGeometry(x, y, 56, 24);
    this->setFont(QFont("Minecraft", 9));
    this->setAlignment(Qt::AlignHCenter);
    this->setStyleSheet("QLabel{ color: white; background-color: transparent; }");
    updateText();

    connect(timer, &QTimer::timeout, this, &Timer::updateTime);
}

void Timer::start()
{
    timer->start(1000);
}

void Timer::stop()
{
    timer->stop();
}

void Timer::updateTime()
{
    time = time.addSecs(-1);
    updateText();

    if(time.toString("m:ss") == "0:00"){
        timer->stop();
        emit ended();
    }
}
