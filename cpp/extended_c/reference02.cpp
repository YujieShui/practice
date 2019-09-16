#include <iostream>

struct  Person
{
    char name[50];
    int age;
};

void printfA(Person *p);
void printfB(Person &p);
void printfC(Person p);

int main()
{
    Person person = {"aaaa", 18};

    std::cout << "==========参数为指针类型==========" << std::endl;

    printfA(&person);
    std::cout << "third time = " << person.age << std::endl;

    std::cout << "==========参数为引用类型==========" << std::endl;

    printfB(person);
    std::cout << "third time = " << person.age << std::endl;

    std::cout << "==========参数为结构体类型==========" << std::endl;

    printfC(person);
    std::cout << "third time = " << person.age << std::endl;

    return 0;
}

// 指针类型，同一块内存上操作
void printfA(Person *p)
{
    std::cout << "first time = " << p->age << std::endl;
    p->age = 20;
    std::cout << "second time = " << p->age << std::endl;
}

// 引用类型，同一块内存上操作
void printfB(Person &p)
{
    std::cout << "first time = " << p.age << std::endl;
    p.age = 30;
    std::cout << "second time = " << p.age << std::endl;

}

// 结构体类型，形参的修改在栈区上
void printfC(Person p)
{
    std::cout << "first time = " << p.age << std::endl;
    p.age = 40;
    std::cout << "second time = " << p.age << std::endl;
}