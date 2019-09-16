/**
 * C++学习笔记: 引用作为函数返回值  
 **/

#include <iostream>

using namespace std;

int getA1()
{
    static int a = 10;
    return a;
}

int &getA2()
{
    static int a = 10;
    return a;
}

int main(void)
{
    int a1 = 0;
    int a2 = 0;

    // 值拷贝
    a1 = getA1();
    cout << "a1 = "	<< a1 << endl;

    // 将一一个引用用赋给一一个变量,会有拷⻉贝动作
    // 理解:编译器类似做了如下隐藏操作, a2 = *(getA2())
    a2 = getA2();
    cout << "a2 = "	<< a2 << endl;

    // 将一一个引用用赋给另一一个引用用作为初始值,由于是静态区域,内存合法
    int &a3 = getA2();
    cout << "a3 = "	<< a3 << endl;

    return 0;
}
