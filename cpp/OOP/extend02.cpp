/* C++学习笔记：面向对象，继承，访问控制 */

#include <iostream>

class Parent
{
private:
    int a;

protected:
    int b;

public:
    int c;

    Parent(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void printP()
    {
        std::cout << "a = " << a
                  << ", b = " << b
                  << ", c = " << c << std::endl;
    }
};

class Child : public Parent
{
public:
    int d;

    Child(int a, int b, int c, int d) : Parent(a, b, c)
    {
        this->d = d;

        // this->a;
        this->b = b;
        this->c = c;
    }

    void printP()
    {
        std::cout << "b = " << b
                  << ", c = " << c
                  << ", d = " << d << std::endl;                
    }
};

int main()
{
    Parent parent(1, 2, 3);
    parent.printP();

    Child child(4, 5, 6, 7);
    child.printP();

    return 0;
}