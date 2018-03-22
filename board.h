#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include"stone.h"
#include<QPoint>

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

    bool isRegularMoveBoss(int selectid ,int row,int col,int killid);
    bool isRegularMoveCHE(int selectid ,int row,int col,int killid);
    bool isRegularMoveMa(int selectid ,int row,int col,int killid);
    bool isRegularMoveXiang(int selectid ,int row,int col,int killid);
    bool isRegularMoveShi(int selectid ,int row,int col,int killid);
    bool isRegularMoveSoldier(int selectid ,int row,int col,int killid);
    bool isRegularMovePao(int selectid ,int row,int col,int killid);

private:
    Stone stone[32];
    int selected ;
    int d ;
    bool bRedTurn ;
private:
    void drawPostion(int x ,int y,int r,QPainter &pen);
    void initStone();

    bool isEXistPieceInLine(int selectid,int row,int col);
    bool isEXistPieceInPoint(int row ,int col);
signals:

public slots:
};

#endif // BOARD_H
