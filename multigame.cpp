#include "multigame.h"
#include <QMouseEvent>
#include <QPoint>
#include<QPushButton>
#include<QBoxLayout>
MultiGame::MultiGame(QWidget *parent) : Board(parent){
    QBoxLayout * layout = new QBoxLayout(QBoxLayout::RightToLeft);
    QPushButton *back = new QPushButton("Back");
    layout->setContentsMargins(400,200,50,200);
    layout->addWidget(back);
    this->setLayout(layout);
    connect(back, SIGNAL(clicked()), this, SLOT(slotBack()));
}
MultiGame::~MultiGame()
{

}


