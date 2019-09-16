/**
 * C++学习笔记：inline 内联函数
 **/
#include <iostream>

using namespace std;

#define MY_MAX(a, b) ((a) < (b) ? (a) : (b))

int my_min(int a, int b)
{
    return (a < b ? a : b);
}

inline int my_max(int a, int b)
{
    return (a > b ? a : b);
}

int main(void)
{
    int a = 10;
    int b = 20;
    int min = 0;

#if 0
    for(int i = 0; i < 1000; i++)
    {
        min = my_min(a, b);
        cout << "min = " << min << endl;

    }
#endif

    int max = 0;

#if 0
    for(int i = 0; i < 1000; i++)
    {
        max = MY_MAX(a++, b++);
        cout << "max = " << max << endl;

    }
#endif

    for(int i = 0; i < 1000; i++)
    {
        max = my_max(a++, b++);
        cout << "max = " << max << endl;
    }

    return 0;
}