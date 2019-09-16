#include <iostream>


int main()
{
    int a = 10; // 定义一个 a
    int &b = a; // 定义一个 a 的引用

    int *p = &a; // 定义一个指向 a 的指针
    *p = 20;

    std::cout << "a = " << a << std::endl;

    b = 30;

    std::cout << "a = " << a << " , b = " << b << std::endl;

    /////////////////////////////////////////////////////

    int c;
    // &b = c;  错误，b 已经是 a 的引用，不可修改引用关系
    // float &f = c; 错误，引用类型不匹配

    int &bb = b; // 可以引用一个引用
    bb = 40;

    std::cout << "a = " << a
         << " , b = " << b
         << " , bb = " << bb << std::endl;

    return 0;
}