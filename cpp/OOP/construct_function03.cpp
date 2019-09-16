/* 面向对象，构造函数与析构函数 */

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <malloc.h>

class Dog
{
private:
    char name[50];
    int age;

public:
    
    Dog(char *dogName, int dogAge)
    {
        std::cout << "调用了构造函数." << std::endl;

        strcpy(name, dogName);
        age = dogAge;
    }

    Dog(const Dog &dog)
    {

        std::cout << "调用了拷贝构造函数." << std::endl;
        
        strcpy(name, dog.name);
        age = dog.age;
    }

    void bark()
    {
        std::cout << name << ": wang wang~~" << std::endl;
    }
};


int main()
{
    Dog dog("bbb", 5);
    dog.bark();

    Dog dog2(dog);
    dog2.bark();

    return 0;    
}