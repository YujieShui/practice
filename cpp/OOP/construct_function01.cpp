/* 面向对象，构造函数与析构函数 */

#include <iostream>
#include <cstring>

class Dog
{
private:
    char name[50];
    int age;

public:
    
    Dog(char *dogName, int dogAge)
    {
        strcpy(name, dogName);
        age = dogAge;
    }


    void initDog(char *dogName, int dogAge)
    {
        strcpy(name, dogName);
        age = dogAge;
    }

    void bark()
    {
        std::cout << name << ": wang wang~~" << std::endl;
    }
};


int main()
{

#if 0
    Dog dog1;
    dog1.initDog("aaa", 3);
    dog1.bark();
#endif

    Dog dog2("bbb", 5);
    dog2.bark();



    return 0;    
}