#ifndef SINGLEGAME_H
#define SINGLEGAME_H
#include "board.h"
#include <QMouseEvent>
#include <QVector>

class SingleGame : public Board
{
    Q_OBJECT
public:
    explicit SingleGame(QWidget *parent = 0);
    ~SingleGame();

    void back();
    void click(int id, int row, int col);

    Step* getBestMove();
    void getALLPossibleMove(QVector<Step *> & );
    void saveAllPossibleMove(int moveid,int killid,int row ,int col ,QVector<Step *> &);
    void fakeMove(Step *);
    void unfakeMove(Step *);
    int calScore();
    int getMinScore(int level,int curMaxScore);
    int getMaxScore(int level,int curMinScore);

private:
    int level ;

signals:

public slots:
    void computerMove();
};

#endif // SINGLEGAME_H
