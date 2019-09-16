#include <iostream>

enum season 
{
    SPRING,
    SUMMER,
    AUTOON,
    WINTER
};

int main()
{

    enum season season = SPRING;
    // season = 1; // 错误, c 语言中可以
    season = SUMMER;

    std::cout << "season = " << season << std::endl; // 1

    return 0;
}