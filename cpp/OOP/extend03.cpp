/* C++学习笔记：面向对象，继承，子类创建和销毁过程 */

#include <iostream>

class Parent
{
public:
    Parent()
    {
        std::cout << "parent()" << std::endl;
    }

    ~Parent()
    {
        std::cout << "~parent" << std::endl;
    }
};

class Child : public Parent
{
public:

    Child()
    {
        std::cout << "child()" << std::endl;        
    }

    void printP()
    {
    
    }

    ~Child()
    {
        std::cout << "~child()" << std::endl;
    }
};

int main()
{

    Child child;

    return 0;
}