#include<QApplication>
#include"board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv) ;

    Board w ;

    w.show();

    return a.exec();
}
