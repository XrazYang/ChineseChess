#include "singlegame.h"
#include <QBoxLayout>
#include <QPushButton>
#include <numeric>
#include <QTimer>
#include <iostream>
SingleGame::SingleGame(QWidget *parent) : Board(parent){
    QBoxLayout * layout = new QBoxLayout(QBoxLayout::RightToLeft);
    QPushButton *back = new QPushButton("Back");
    layout->setContentsMargins(400,200,50,200);
    layout->addWidget(back);
    this->setLayout(layout);
    connect(back, SIGNAL(clicked()), this, SLOT(slotBack()));
}
SingleGame::~SingleGame(){

}

void SingleGame::click(int id, int row, int col){
    if(!this->bRedTurn){
        return ;
    }
    Board::click(id,row,col);

    if(!this->bRedTurn)
        QTimer::singleShot(100, this, SLOT(computerMove()));
}
void SingleGame::computerMove(){
    Step * step = this->getBestMove();
    this->moveStone(step->_moveid, step->_killid, step->_rowTo, step->_colTo);
    this->restartGame();
    selected = -1;
    delete step ;
    update();
}

void SingleGame::saveAllPossibleMove(int moveid, int killid, int row, int col, QVector<Step *>& steps){
    Step* step = new Step;
    step->_colFrom = stone[moveid].getCol();
    step->_colTo = col;
    step->_rowFrom = stone[moveid].getRow();
    step->_rowTo = row;
    step->_moveid = moveid;
    step->_killid = killid;
    steps.push_back(step);
}
void SingleGame::getALLPossibleMove(QVector<Step *> & steps){

    //id [16,31] is black
    for(int i = 16 ; i < 32 ; i++){
        if(this->stone[i].getIsDead())continue;
        for(int row = 1 ; row <= 9 ; row ++){
            for(int col = 1 ; col <= 10 ; col ++){
                int killid = this->getStoneId(row *d,col*d);
                if(this->isRegularMovement(i,row*d,col*d,killid)){
                    this->saveAllPossibleMove(i,killid,row*d,col*d,steps);
                }
            }
        }
    }
}

void SingleGame::fakeMove(Step *step){
    // smiliar move step
    this->killStone(step->_killid);
    this->moveStone(step->_moveid,step->_rowTo,step->_colTo);
}
void SingleGame::unfakeMove(Step *step){
    //smiliar back step
    this->reliveStone(step->_killid);
    this->moveStone(step->_moveid, step->_rowFrom, step->_colFrom);
}
int SingleGame::calScore(){
    //enum TYPE{JIANG,SHUAI,BING,ZU,REDPAO,BLACKPAO,REDCHE,BLACKCHE,REDMA,BLACKMA,BLACKXIANG,REDXIANG,REDSHI,BLACKSHI};
    static int chessScore[] = {1000,1000,20,20,50,50,100,100,50,50,10,10,10,10};
    int redScore = 0 ;
    int blackScore = 0 ;

    for(int i = 0 ; i < 16 ; i++){
        if(!this->stone[i].getIsDead()){
            redScore += chessScore[this->stone[i].type];
        }
    }

    for(int i = 16 ; i < 32 ; i++){
        if(!this->stone[i].getIsDead()){
            blackScore += chessScore[this->stone[i].type];
        }
    }
    return (blackScore - redScore) ;
}

Step* SingleGame::getBestMove(){
    //computer move
    QVector<Step*>steps ;
    //1.get all possible move steps
    this->getALLPossibleMove(steps);

    //2.try to move
    int maxScore = std::numeric_limits<int>::min();
    Step * realstp ;
    for(QVector<Step*>::const_iterator it = steps.begin() ; it != steps.end(); ++it){
        Step * step = *it ;
        fakeMove(step);

        //3.assess each step
        int score = calScore();
        unfakeMove(step);

        if(score > maxScore){
            maxScore = score ;
            realstp = step ;
        }
    }
    //get best move step
    return realstp ;
}
void SingleGame::back(){
    backOne();
    backOne();
}
