#ifndef MULTIGAME_H
#define MULTIGAME_H

#include "board.h"
#include <QMouseEvent>

class MultiGame : public Board
{
    Q_OBJECT
public:
    explicit MultiGame(QWidget *parent = 0);
    ~MultiGame();
    void mouseReleaseEvent(QMouseEvent *);
private:


signals:

public slots:
};

#endif // MULTIGAME_H
