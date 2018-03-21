#ifndef STONE_H
#define STONE_H
#include<QString>
class Stone
{
public:
    QString getSoneName();
    int getRow();
    int getCol();
    int getId();
    bool getIsDead();

    void setRow(int x);
    void setCol(int y);
    void setIsDead(bool isdead);

public:
    enum TYPE{JIANG,SHUAI,BING,ZU,REDPAO,BLACKPAO,REDCHE,BLACKCHE,REDMA,BLACKMA,BLACKXIANG,REDXIANG,REDSHI,BLACKSHI};
    enum COLOR{RED=1,BLACK=2};
public:
    TYPE type ;
    COLOR color ;

private:
    int row;
    int col ;
    int id ;
    bool isdead;

public:
    Stone();
    Stone(int row,int col,int id,bool isdead, COLOR color,TYPE type);
};

#endif // STONE_H
