#ifndef NETGAME_H
#define NETGAME_H

#include "board.h"
#include <QTcpServer>
#include <QTcpSocket>

class NetGame : public Board
{
    Q_OBJECT
public:
    NetGame(bool isServer,QWidget *parent = 0);
    void back();
    void click(int id, int row, int col);

    void backFromNetwork(QByteArray buf);
    void clickFromNetwork(QByteArray buf);
    void initFromNetwork(QByteArray buf);

private:
    QTcpServer * server ;
    QTcpSocket * client ;
signals:

public slots:
    void slotNewConnection();
    void slotDataArrive();
};

#endif // NETGAME_H
