#include <QApplication>
#include <QLabel>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog q;
    QLabel label(&q);
    label.setText("hello word !!!");
    q.show();
    return a.exec();
}
