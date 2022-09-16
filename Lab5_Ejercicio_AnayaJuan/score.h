#ifndef SCORE_H
#define SCORE_H

#include <QLabel>
#include <QFont>

class Score : public QLabel
{
private:
    int score;

    void updateText();

public:
    Score(const int &x, const int &y);

    void increase();
};

#endif // SCORE_H
