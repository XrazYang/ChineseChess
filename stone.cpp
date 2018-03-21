#include "stone.h"

Stone::Stone()
{

}
Stone::Stone(int row, int col, int id, bool isdead, COLOR color, TYPE type){
    this->row = row ;
    this->col = col;
    this->id = id;
    this->isdead = isdead;
    this->color = color;
    this->type = type ;
}

QString Stone::getSoneName(){
    switch (this->type) {
    case JIANG:
       return QString("將");
    case SHUAI:
        return QString("帥");
    case BING:
        return QString("兵");
    case ZU:
        return QString("卒");
    case REDPAO:
        return QString("炮");
    case BLACKPAO:
        return QString("砲");
    case BLACKSHI:
        return QString("士");
    case REDSHI:
        return QString("仕");
    case BLACKCHE:
        return QString("車");
    case REDCHE:
        return QString("俥");
    case BLACKMA:
        return QString("馬");
    case REDMA:
        return QString("傌");
    case BLACKXIANG:
        return QString("象");
    case REDXIANG:
        return QString("相");
    default:
        return QString("error");
    }
}
int Stone::getRow(){
    return this->row;
}
int Stone::getCol(){
    return this->col;
}
int Stone::getId(){
    return this->id;
}
bool Stone::getIsDead(){
    return this->isdead;
}

void Stone::setRow(int x){
    this->row = x ;
}
void Stone::setCol(int y){
    this->col = y ;
}
void Stone::setIsDead(bool isdead){
    this->isdead = isdead;
}
