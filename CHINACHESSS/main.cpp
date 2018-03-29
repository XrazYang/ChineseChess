#include "mainwidget.h"
#include <QApplication>
#include "multigame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
    //MultiGame w ;
    w.show();

    return a.exec();
}
