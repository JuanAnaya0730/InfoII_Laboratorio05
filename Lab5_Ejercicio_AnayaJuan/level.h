#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QString>

class Level : public QGraphicsScene
{
    Q_OBJECT
private:
    void loadLevel(const QString &filename);

public:
    explicit Level(const QString &fileName, QObject *parent = nullptr);
};

#endif // LEVEL_H
