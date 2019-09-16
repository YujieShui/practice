/* C++学习笔记： 默认参数与占位符 */

#include <iostream>

int function_name(int a, int b = 10)
{
    std::cout << "a = " << a << " b = " << b << std::endl;
}

int main()
{
    int a = 20;
    int b = 30;

    function_name(a, b);
    function_name(a);

    return 0;
}