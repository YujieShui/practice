#include <iostream>

int main()
{
    int a = 10;
    int b = 20;

    (a < b ? a : b) = 30;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}