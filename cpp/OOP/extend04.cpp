/* C++学习笔记：面向对象，继承， */

#include <iostream>

class Parent
{
public:
    int aaa;
};

class Child1 : virtual public Parent
{
public:
    int b;
};

class Child2 : virtual public Parent
{
public:
    int c;
};

class GrandSon: public Child1, public Child2
{
public:
    void printG()
    {
        std::cout << b << std::endl;
        std::cout << aaa << std::endl;
    }
};

int main()
{
    GrandSon grandSon;
    

    return 0;
}