#include <QApplication>
#include"board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Board Board;
    Board.show();
    return a.exec();
}
