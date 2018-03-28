#include "netgame.h"
#include<QBoxLayout>
#include<QPushButton>

NetGame::NetGame(bool isServer,QWidget *parent) : Board(parent){
    this->server = NULL ;
    this->client = NULL ;
    if(isServer){
        this->server = new QTcpServer(this);
        this->server->listen(QHostAddress::Any,8999);
        connect(this->server,SIGNAL(newConnection()),this,SLOT(slotNewConnection()));

    }else{
        QBoxLayout * layout = new QBoxLayout(QBoxLayout::RightToLeft);
        QPushButton *back = new QPushButton("Back");
        layout->setContentsMargins(400,200,50,200);
        layout->addWidget(back);
        this->setLayout(layout);
        connect(back, SIGNAL(clicked()), this, SLOT(slotBack()));

        this->client = new QTcpSocket(this);
        this->client->connectToHost(QHostAddress("127.0.0.1"),8999);
    }
}

void NetGame::slotNewConnection(){
    if(this->client == NULL){
        this->client = this->server->nextPendingConnection();
    }
}
