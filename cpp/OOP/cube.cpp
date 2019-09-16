/**
 * 1. 设计立方体类(cube),求出立方体的面积和体积
 * 2. 求两个立方体,是否相等(全局函数和成员函数) 
 **/

#include <iostream>

class Cube
{
private:
    double a;
    double b;
    double c;
public:
    // 计算面积
    double getArea()
    {
        return a * b + b * c + c * a;
    }

    // 计算面积
    double getVolume()
    {
        return a * b * c;
    }

    // 判断两个矩形是否相同
    bool judge(Cube &cube)
    {
        if(cube.a == a && cube.b == b && cube.c == c)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    } 

    void setCube(double aa, double bb, double cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }

    double getA()
    {
        return a;
    }

    double getB()
    {
        return b;
    }
    
    double getC()
    {
        return c;
    }
};


int main()
{

    Cube cube1, cube2;

    cube1.setCube(10, 20, 30);
    std::cout << "area = " << cube1.getArea() << std::endl;
    std::cout << "volume = " << cube1.getVolume() << std::endl;
    
    cube2.setCube(10, 20, 30);
    
    if(cube1.judge(cube2))
    {
        std::cout << "两个矩阵相同" << std::endl;
    }
    else
    {
        std::cout << "两个矩阵不同" << std::endl;
    }
    

    return 0;
}