/* OOP: 面向过程的方式计算圆的周长和面积 */

#include <iostream>

int main()
{
    const double PI = 3.14;

    double r, girth, area;

    r = 3;

    girth = 2*PI*r;
    area = PI * r * r;

    std::cout << "r = " << r << std::endl;
    std::cout << "girth = " << girth << std::endl;
    std::cout << "area = " << area << std::endl;
    
    return 0;
}