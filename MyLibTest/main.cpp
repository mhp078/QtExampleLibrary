#include <QCoreApplication>

#include <mylib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyLib mylib;

    mylib.Test_1();
    mylib.Test_2();

    return a.exec();
}
