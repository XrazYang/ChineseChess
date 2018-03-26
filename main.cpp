#include <QApplication>
#include"board.h"
#include "multigame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MultiGame board;
    //Board board;
    board.show();
    return a.exec();
}
