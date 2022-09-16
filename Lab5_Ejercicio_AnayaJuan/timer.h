#ifndef TIMER_H
#define TIMER_H

#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QTime>

class Timer : public QLabel
{
    Q_OBJECT
private:
    QTime time;
    QTimer *timer;

    void updateText();

public:
    explicit Timer(const int &x, const int &y);
    void start();
    void stop();

signals:
    void ended();

public slots:
    void updateTime();
};

#endif // TIMER_H
