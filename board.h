/**
  Board

**/

#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "stone.h"
#include<QPainter>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);
    Stone stone[32];
    int r ;

    QPoint center(int row ,int col );
    QPoint center(int id);



    void drawStone(QPainter & painter,int id );

    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // BOARD_H
