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

private:
    QTcpServer * server ;
    QTcpSocket * client ;
signals:

public slots:
    void slotNewConnection();
};

#endif // NETGAME_H
