#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

class Level : public QObject
{
    Q_OBJECT
public:
    explicit Level(QObject *parent = nullptr);

signals:

};

#endif // LEVEL_H
