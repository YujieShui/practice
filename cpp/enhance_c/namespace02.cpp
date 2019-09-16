#include <iostream>
#include "stdio.h"

namespace NamespaceA
{
    int a = 1;
}

namespace NamespaceB
{
    int a = 2;

    namespace NamespaceC
    {
        struct Person
        {
            char name[50];
            int age;
        };
    }
}

int main()
{

    using namespace NamespaceA;
    using NamespaceB::NamespaceC::Person;

    printf("a = %d\n", a); // 1
    printf("a = %d\n", NamespaceB::a); // 2

    Person person = {"aaa", 1};
    printf("name = %s, age = %d\n", person.name, person.age); // aaa, 1

    return 0;
}