#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include"stone.h"
#include<QPoint>
#include "step.h"
#include <QVector>

/**
 * @brief The Board class
 */
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    QPoint& getRowCol(QPoint &pen);

    void drawStone(int id,QPainter &pen);
    bool isRegularMovement(int selectid ,int row,int col,int killid);

    bool isRegularMoveBoss(int selectid ,int row,int col);
    bool isRegularMoveCHE(int selectid ,int row,int col);
    bool isRegularMoveMa(int selectid ,int row,int col);
    bool isRegularMoveXiang(int selectid ,int row,int col);
    bool isRegularMoveShi(int selectid ,int row,int col);
    bool isRegularMoveSoldier(int selectid ,int row,int col);
    bool isRegularMovePao(int selectid ,int row,int col,int killid);
    int whoWinTheGame();
    void restartGame();

    //
    void click(QPoint pt);
    virtual void click(int id, int row, int col);
    int getStoneId(int row, int col);
    void trySelectStone(int id);
    void tryMoveStone(int killid, int row, int col);
    void moveStone(int moveid, int killid, int row, int col);
    void saveStep(int moveid, int killid, int row, int col);
    void killStone(int id);
    void moveStone(int moveid, int row, int col);

    //
    virtual void back();
    void reliveStone(int id);
    void backOne();
    void back(Step *step);

protected:
    Stone stone[32];
    int selected ;
    int d ;
    bool bRedTurn ;
    QVector<Step *> steps ;

private:
    void drawPostion(int x ,int y,int r,QPainter &pen);
    void initStone();

    bool isEXistPieceInLine(int selectid,int row,int col);
    int countPieceInLine(int selectid,int row,int col);
    bool isEXistPieceInPoint(int row ,int col);
signals:

public slots:
    void slotBack();
};

#endif // BOARD_H
