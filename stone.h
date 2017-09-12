#ifndef STONE_H
#define STONE_H

#include<QString>

class Stone
{
public:
    Stone();

    enum TYPE {JIANG,CHE,PAO,MA,BING,SHI,XIANG};

    int row ;
    int col ;
    int id ;
    bool isDead ;
    bool isRed ;
    TYPE type ;

    QString getText();
    void init(int id);
};

#endif // STONE_H
