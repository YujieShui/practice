/* OOP: 面向对象的方式计算圆的周长和面积 */

#include <iostream>

class Circle
{
private:
    double radius;

public:
    void setR(double r)
    {
        radius = r;
    }

    double getR()
    {
        return radius;
    }

    double getGrius()
    {
        return 2 * 3.14f * radius;
    }

    double getArea()
    {
        return 3.14f * radius * radius;
    }
};


int main()
{
    
    Circle circle;
    circle.setR(3);

    std::cout << "r = " << circle.getR() << std::endl;
    std::cout << "girth = " << circle.getGrius() << std::endl;
    std::cout << "area = " << circle.getArea() << std::endl;

    return 0;
}