#ifndef MYLIB_H
#define MYLIB_H

#include <QDebug>

#include "MyLib_global.h"

class MYLIB_EXPORT MyLib
{
public:
    MyLib();

    void Test_2();

    void Test_1()
    {
        qDebug() << "Test 1 Method!";
    }
};

#endif // MYLIB_H
