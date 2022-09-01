#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>

class Level : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Level(QObject *parent = nullptr);

signals:

};

#endif // LEVEL_H
