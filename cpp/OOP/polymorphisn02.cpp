/* C++学习笔记：面向对象，多态*/
#include <iostream>

class Animal
{
private:
    std::string name;

public:
    virtual void bark()
    {
        std::cout << "动物叫..." << std::endl;
    }
    
    virtual void bark(std::string name)
    {
        std::cout << name << "正在叫..." << std::endl;
    }
};

class Dog: public Animal
{
public:
    void bark()
    {
        std::cout << "wang wang wang ..." << std::endl;
    }
};

class Cat: public Animal
{
public:
    void bark()
    {
        std::cout << "miao miao miao ..." << std::endl;
    }
};

void animalBark(Animal *animal)
{
    animal->bark();
}

int main()
{
    Animal *animal = new Animal();
    Dog *dog = new Dog();
    Cat *cat = new Cat();

    animalBark(animal);
    animalBark(dog);
    animalBark(cat);

    return 0;
}