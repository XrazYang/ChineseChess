#include <QApplication>
#include"board.h"
#include "multigame.h"
#include "singlegame.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MultiGame board;
    //Board board;
    SingleGame board ;
    board.show();
    return a.exec();
}
