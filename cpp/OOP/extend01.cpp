/* 面向对象，继承 */
#include <iostream>
#include <string>

// 父类：动物
class Animal
{
private:
    int age;
    std::string name;

public:

    Animal()
    {

    }

    Animal(int age, std::string name)
    {
        this->age = age;
        this->name = name;
    }

    void bark()
    {
        std::cout << "animal can bark ~~~" << std::endl;
    }
};

// 子类：狗
class Dog : public Animal
{

private:
    int size;

public:

    Dog()
    {

    }

    Dog(int age, std::string name, int size) : Animal(age, name)
    {
        this->size = size;
    }

    void dogBark()
    {
        std::cout << "i am a dog." << std::endl;
    }
};

int main()
{

    Animal animal;
    animal.bark();

    Dog dog;
    dog.bark();
    dog.dogBark();

    return 0;
}