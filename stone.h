#ifndef STONE_H
#define STONE_H
#include<QString>
class Stone
{
public:
    enum TYPE{JIANG,SHUAI,BING,ZU,REDPAO,BLACKPAO,REDCHE,BLACKCHE,REDMA,BLACKMA,BLACKXIANG,REDXIANG,REDSHI,BLACKSHI};
    QString getSoneName();
    int getRow();
    int getCol();
    int getId();
    bool getIsDead();
    bool getIsRed();


    void setRow(int x);
    void setCol(int y);
    void setIsDead(bool isdead);
    void setIsRed(bool isred);

private:
    int row;
    int col ;
    int id ;
    bool isdead;
    bool isred ;

    TYPE type ;
public:
    Stone();
    Stone(int row,int col,int id,bool isdead,bool isred,TYPE type);

};

#endif // STONE_H
