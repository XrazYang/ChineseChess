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

private:
    Stone stone[32];
    int selected ;
    int d ;
private:
    void drawPostion(int x ,int y,int r,QPainter &pen);
    void initStone();
signals:

public slots:
};

#endif // BOARD_H
