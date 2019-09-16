/**
 * C++学习笔记: const引用
 **/

#include <iostream>

int main()
{
    const int a = 10;
    // int &b = a;
    const int &b = a;

    int c = 20;
    const int &d = c;
    // d = 30;
    c = 30;


    return 0;
}