/* 面向对象，构造函数与析构函数 */

#include <iostream>
#include <cstring>

class Dog
{
private:
    char *name;
    int age;

public:
    
    Dog(char *dogName, int dogAge)
    {
        std::cout << "调用了构造函数." << std::endl;

        name = new char[50];
        strcpy(name, dogName);
        age = dogAge;
    }

    void bark()
    {
        std::cout << name << ": wang wang~~" << std::endl;
    }

    ~Dog()
    {
        std::cout << "调用了析构函数." << std::endl;

        if(name != NULL)
        {
            delete name;
            name = NULL;
        }
    }
};


int main()
{
    Dog dog2("bbb", 5);
    dog2.bark();

    return 0;    
}