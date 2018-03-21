#include "board.h"
#include<QPainter>
#include<QMouseEvent>
#include<iostream>

Board::Board(QWidget *parent) : QWidget(parent)
{
    selected = -1 ;
    d = 40 ;
    bRedTurn = true ; //red first
    initStone();
    this->setWindowTitle(QString("中国象棋"));
}
void Board::drawPostion(int x, int y,int r ,QPainter &pen){
    if(x == d){
        pen.drawLine(QPoint(x+r,y-r),QPoint(x+r,y-2*r));
        pen.drawLine(QPoint(x+r,y-r),QPoint(x+2*r,y-r));

        pen.drawLine(QPoint(x+r,y+r),QPoint(x+r,y+2*r));
        pen.drawLine(QPoint(x+r,y+r),QPoint(x+2*r,y+r));
    }
    else if( x == 9*d){
        pen.drawLine(QPoint(x-r,y-r),QPoint(x-r,y-2*r));
        pen.drawLine(QPoint(x-r,y-r),QPoint(x-2*r,y-r));

        pen.drawLine(QPoint(x-r,y+r),QPoint(x-r,y+2*r));
        pen.drawLine(QPoint(x-r,y+r),QPoint(x-2*r,y+r));

    }else{
        pen.drawLine(QPoint(x-r,y-r),QPoint(x-r,y-2*r));
        pen.drawLine(QPoint(x-r,y-r),QPoint(x-2*r,y-r));

        pen.drawLine(QPoint(x+r,y-r),QPoint(x+r,y-2*r));
        pen.drawLine(QPoint(x+r,y-r),QPoint(x+2*r,y-r));

        pen.drawLine(QPoint(x+r,y+r),QPoint(x+2*r,y+r));
        pen.drawLine(QPoint(x+r,y+r),QPoint(x+r,y+2*r));

        pen.drawLine(QPoint(x-r,y+r),QPoint(x-2*r,y+r));
        pen.drawLine(QPoint(x-r,y+r),QPoint(x-r,y+2*r));
    }
}
void Board::initStone(){
    //0-15 is red
    stone[0] = Stone(d,10*d,0,false,Stone::RED,Stone::REDCHE);
    stone[1] = Stone(2*d,10*d,1,false,Stone::RED,Stone::REDMA);
    stone[2] = Stone(3*d,10*d,2,false,Stone::RED,Stone::REDXIANG);
    stone[3] = Stone(4*d,10*d,3,false,Stone::RED,Stone::REDSHI);
    stone[4] = Stone(5*d,10*d,4,false,Stone::RED,Stone::SHUAI);
    stone[5] = Stone(6*d,10*d,5,false,Stone::RED,Stone::REDSHI);
    stone[6] = Stone(7*d,10*d,6,false,Stone::RED,Stone::REDXIANG);
    stone[7] = Stone(8*d,10*d,7,false,Stone::RED,Stone::REDMA);
    stone[8] = Stone(9*d,10*d,8,false,Stone::RED,Stone::REDCHE);

    stone[9] = Stone(d,7*d,9,false,Stone::RED,Stone::BING);
    stone[10] = Stone(3*d,7*d,10,false,Stone::RED,Stone::BING);
    stone[11] = Stone(5*d,7*d,11,false,Stone::RED,Stone::BING);
    stone[12] = Stone(7*d,7*d,12,false,Stone::RED,Stone::BING);
    stone[13] = Stone(9*d,7*d,13,false,Stone::RED,Stone::BING);

    stone[14] = Stone(2*d,8*d,14,false,Stone::RED,Stone::REDPAO);
    stone[15] = Stone(8*d,8*d,15,false,Stone::RED,Stone::REDPAO);

    //16 -31 id black
    stone[16] = Stone(d,d,16,false,Stone::BLACK,Stone::BLACKCHE);
    stone[17] = Stone(2*d,d,17,false,Stone::BLACK,Stone::BLACKMA);
    stone[18] = Stone(3*d,d,18,false,Stone::BLACK,Stone::BLACKXIANG);
    stone[19] = Stone(4*d,d,19,false,Stone::BLACK,Stone::BLACKSHI);
    stone[20] = Stone(5*d,d,20,false,Stone::BLACK,Stone::JIANG);
    stone[21] = Stone(6*d,d,21,false,Stone::BLACK,Stone::BLACKSHI);
    stone[22] = Stone(7*d,d,22,false,Stone::BLACK,Stone::BLACKXIANG);
    stone[23] = Stone(8*d,d,23,false,Stone::BLACK,Stone::BLACKMA);
    stone[24] = Stone(9*d,d,24,false,Stone::BLACK,Stone::BLACKCHE);

    stone[25] = Stone(d,4*d,25,false,Stone::BLACK,Stone::ZU);
    stone[26] = Stone(3*d,4*d,26,false,Stone::BLACK,Stone::ZU);
    stone[27] = Stone(5*d,4*d,27,false,Stone::BLACK,Stone::ZU);
    stone[28] = Stone(7*d,4*d,28,false,Stone::BLACK,Stone::ZU);
    stone[29] = Stone(9*d,4*d,29,false,Stone::BLACK,Stone::ZU);

    stone[30] = Stone(2*d,3*d,30,false,Stone::BLACK,Stone::BLACKPAO);
    stone[31] = Stone(8*d,3*d,31,false,Stone::BLACK,Stone::BLACKPAO);
}
void Board::drawStone(int id,QPainter &pen){
    if(!stone[id].getIsDead()){
        if(selected == id){
            pen.setBrush(Qt::gray);
        }else pen.setBrush(QBrush(Qt::yellow));

        if(stone[id].color == Stone::RED){
            pen.setPen(Qt::red);
            pen.drawEllipse(QPoint(stone[id].getRow(),stone[id].getCol()),d/2,d/2);
            pen.drawEllipse(QPoint(stone[id].getRow(),stone[id].getCol()),d/2-1,d/2-1);
            pen.drawEllipse(QPoint(stone[id].getRow(),stone[id].getCol()),d/2-2,d/2-2);
            pen.drawText(QRectF(stone[id].getRow()-10,stone[id].getCol()-10,20,20),Qt::AlignCenter,stone[id].getSoneName());
        }else{
            pen.setPen(Qt::black);
            pen.drawEllipse(QPoint(stone[id].getRow(),stone[id].getCol()),d/2,d/2);
            pen.drawEllipse(QPoint(stone[id].getRow(),stone[id].getCol()),d/2-1,d/2-1);
            pen.drawEllipse(QPoint(stone[id].getRow(),stone[id].getCol()),d/2-2,d/2-2);
            pen.drawText(QRectF(stone[id].getRow()-10,stone[id].getCol()-10,20,20),Qt::AlignCenter,stone[id].getSoneName());
        }
    }
}
void Board::paintEvent(QPaintEvent *){
    QPainter pen(this);

    int r = 5 ;
    for(int i = 1 ; i <= 10 ; i++){
        pen.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }

    for(int i = 1 ; i <= 9 ; i ++){
        if(i >=2 && i <= 8){
            pen.drawLine(QPoint(i*d,d),QPoint(i*d,5*d));
            pen.drawLine(QPoint(i*d,6*d),QPoint(i*d,10*d));

        }else{
            pen.drawLine(QPoint(i*d,d),QPoint(i*d,10*d));
        }
    }

    pen.drawLine(QPoint(4*d,d),QPoint(6*d,3*d));
    pen.drawLine(QPoint(4*d,3*d),QPoint(6*d,d));

    pen.drawLine(QPoint(4*d,8*d),QPoint(6*d,10*d));
    pen.drawLine(QPoint(4*d,10*d),QPoint(6*d,8*d));

    pen.drawText(QRectF(QRect(2.3*d,5*d+5,d,d)),QString("楚"));
    pen.drawText(QRectF(QRect(3.3*d,5*d+5,d,d)),QString("河"));
    pen.drawText(QRectF(QRect(6.3*d,5*d+5,d,d)),QString("汉"));
    pen.drawText(QRectF(QRect(7.3*d,5*d+5,d,d)),QString("界"));

    drawPostion(d,4*d,r,pen);
    drawPostion(9*d,4*d,r,pen);
    drawPostion(d,7*d,r,pen);
    drawPostion(9*d,7*d,r,pen);

    drawPostion(2*d,3*d,r,pen);
    drawPostion(8*d,3*d,r,pen);
    drawPostion(2*d,8*d,r,pen);
    drawPostion(8*d,8*d,r,pen);

    drawPostion(3*d,4*d,r,pen);
    drawPostion(5*d,4*d,r,pen);
    drawPostion(7*d,4*d,r,pen);

    drawPostion(3*d,7*d,r,pen);
    drawPostion(5*d,7*d,r,pen);
    drawPostion(7*d,7*d,r,pen);

    for(int i = 0 ; i < 32 ; i++){
        drawStone(i,pen);
    }
}
void Board::mouseReleaseEvent(QMouseEvent *ev){
    int clicked = -1 ;
    int i = 0 ;
    QPoint pt = ev->pos();
    getRowCol(pt);
    if(pt.x() != 0 && pt.y() != 0){
        for(i = 0 ; i < 32 ; i++){
            if(stone[i].getRow() == pt.x() && stone[i].getCol() == pt.y() && stone[i].getIsDead() == false){
                break;
            }
        }

        if(i < 32){
            clicked = i ;
        }
        if(selected == -1){
            if(clicked != -1){
                if((bRedTurn == true && stone[clicked].color == Stone::RED) ||(bRedTurn == false && stone[clicked].color == Stone::BLACK) ){
                    selected = clicked;
                    update();
                }
            }

        }else{
            if(isRegularMovement(selected,pt.x(),pt.y(),clicked)){
                if(selected != clicked){
                    stone[selected].setRow(pt.x());
                    stone[selected].setCol(pt.y());
                    if(clicked != -1){
                        stone[clicked].setIsDead(true);
                    }
                }
                selected = -1;
                bRedTurn = !bRedTurn;
                update();
            }
        }
    }
}
QPoint& Board::getRowCol(QPoint &pen){
    int r = d/2 ;
    int x = pen.x();
    int y = pen.y();
    if((x >= (d-r) && x <= 9*d+r) && (y >= d - r && y <= 10*d + r)){
        for(int i = 1 ; i <= (x+r)%d ; i++){
            for(int j = 1 ; j <= (y+r)%d ; j++){
                if(((i*d - x )*(i*d - x) + (j * d -y)*(j * d -y)) <= r*r){
                    pen.setX(i*d);
                    pen.setY(j*d);
                    return pen ;
                }
            }
        }
    }
    pen.setX(0);
    pen.setY(0);
    return pen ;
}

bool Board::isRegularMovement(int selectid, int row, int col, int killid){
    if(stone[selectid].color == stone[killid].color){
        this->selected = killid ;
        update();
        return false ;
    }

    switch(stone[selectid].type){
    case Stone::JIANG:
    case Stone::SHUAI:{
        return isRegularMoveBoss(selectid,row,col,killid);
    }
        //    case Stone::REDCHE:
        //    case Stone::BLACKCHE:{
        //        return isRegularMoveCHE(selectid,row,col,killid);
        //    }
        //    case Stone::REDMA:
        //    case Stone::BLACKMA:{
        //        return isRegularMoveMa(selectid,row,col,killid);
        //    }
        //    case Stone::REDXIANG:
        //    case Stone::BLACKXIANG:{
        //        return isRegularMoveXiang(selectid,row,col,killid);
        //    }
        //    case Stone::REDSHI:
        //    case Stone::BLACKSHI:{
        //        return isRegularMoveShi(selectid,row,col,killid);
        //    }
        //    case Stone::BING:
        //    case Stone::ZU:{
        //        return isRegularMoveSoldier(selectid,row,col,killid);
        //    }
        //    case Stone::REDPAO:
        //    case Stone::BLACKPAO:{
        //        return isRegularMovePao(selectid,row,col,killid);
        //    }
        //    default:
        //        std::cout<<stone[selectid].getIsRed()<<std::endl ;
        //        return false;
    }
    return true ;
}

bool Board::isRegularMoveBoss(int selectid ,int row,int col,int killid){
    if(stone[selectid].color == Stone::BLACK){
        if(col < d || col > 3*d ){
            return false;
        }
    }
    if(stone[selectid].color == Stone::RED){
        if(col < 8*d || col > 10*d ){
            return false;
        }
    }
    if( row < 4*d || row > 6*d) return false ;

    int drow = abs(stone[selectid].getRow() - row);
    int dcol = abs(stone[selectid].getCol() - col);
    if(!((drow == 0 && dcol == d) || (drow == d && dcol == 0) )){
        return false ;
    }

    //
    if(drow == d){
        for(int j = 0 ; j < 32 ; j++){
            if(stone[j].getRow() == row && (stone[j].type ==Stone::JIANG || stone[j].type == Stone::SHUAI)){
                return false;
            }
        }
    }
    return true ;
}
bool Board::isRegularMoveCHE(int selectid ,int row,int col,int killid){
    return true ;
}
bool Board::isRegularMoveMa(int selectid ,int row,int col,int killid){
    return true ;
}
bool Board::isRegularMoveXiang(int selectid ,int row,int col,int killid){
    return true ;
}
bool Board::isRegularMoveShi(int selectid ,int row,int col,int killid){
    return true ;
}
bool Board::isRegularMoveSoldier(int selectid ,int row,int col,int killid){
    return true ;
}
bool Board::isRegularMovePao(int selectid ,int row,int col,int killid){
    return true ;
}
