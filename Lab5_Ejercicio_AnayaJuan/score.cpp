#include "score.h"

Score::Score(const int &x, const int &y): score(0)
{
    this->setGeometry(x, y, 56, 24);
    this->setFont(QFont("Minecraft", 9));
    this->setAlignment(Qt::AlignHCenter);
    this->setStyleSheet("QLabel{ color: white; background-color: transparent; }");
    updateText();
}

void Score::updateText()
{
    this->setText("SCORE\n" + QString::number(score));
}

const int &Score::getScore() const
{
    return score;
}

void Score::increase()
{
    score += 10;
    updateText();
}
