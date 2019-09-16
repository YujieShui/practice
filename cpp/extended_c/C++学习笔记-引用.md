# 引用的基本规则

```c++
#include <iostream>

int main()
{
    int a = 10; // 定义一个 a
    int &b = a; // 定义一个 a 的引用

    int *p = &a; // 定义一个指向 a 的指针
    *p = 20;

    std::cout << "a = " << a << std::endl;

    b = 30;

    std::cout << "a = " << a << " , b = " << b << std::endl;

    /////////////////////////////////////////////////////

    int c;
    // &b = c;  错误，b 已经是 a 的引用，不可修改引用关系
    // float &f = c; 错误，引用类型不匹配

    int &bb = b; // 可以引用一个引用
    bb = 40;

    std::cout << "a = " << a
         << " , b = " << b
         << " , bb = " << bb << std::endl;

    return 0;
}
```

1. 引用的使用方式 `typename &b = a`, & 符号前有符号表示引用，否则表示取地址
2. 引用是一种关系申明，表示它和某个变量的关系，它们类型相同，并共享一片内存
3. 引用一经申明就不可以修改
4. 可以引用一个引用

# 引用作为函数参数

```c++
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
```

```
==========参数为指针类型==========
first time = 18
second time = 20
third time = 20
==========参数为引用类型==========
first time = 20
second time = 30
third time = 30
==========参数为结构体类型==========
first time = 30
second time = 40
third time = 30
```

以上这段代码分别将一个结构体用指针形式、引用形式和结构体变量形式作为形参传入到函数中，并对其值进行修改，最后打印结果。

我们可以看到指针类型和引用类型对变量进行修改，因为它们都指向同一块内存。结构体类型，形参的修改在栈区上，并不会对堆区中的结构体变量本身产生影响。

*注：关于堆区、栈区的内存四区概念有问题可以看 [C语言学习笔记-指针01
](https://shuiyujie.com/post/2f02c8ae.html)。*

1. 引用是一个变量的别名，有时候起到和指针一样的效果
2. 引用比指针具有更强的可读性

# 引用作为函数返回值

- 若返回栈变量: 不能成为其它引用的初始值(不能作为左值使用)
- 若返回静态变量或全局变量: 可以成为其他引用的初始值(可作为右值使用,也可作为左值使用)

1. [引用作为函数返回-值返回栈变量代码示例](reference03.cpp)
2. [引用作为函数返回-值返回静态变量代码示例](reference04.cpp)

# 指针引用

都在代码里了，关键代码如下，[点击查看完整示例](reference05.cpp)

```c++
int getTeacher(Teacher **teacher)
{
    Teacher *t = NULL;
    t = (Teacher*)malloc(sizeof(Teacher));

    if(t == NULL)
    {
        return -1;
    }

    strcpy(t->name, "Mary");
    t->age = 30;

    *teacher = t;

    return 0;
}

int getTeacher02(Teacher *&teacher)
{
    teacher = (Teacher *)malloc(sizeof(Teacher));
    if(teacher == NULL)
    {
        return -1;
    }

    strcpy(teacher->name, "Lucy");
    teacher->age = 20;
    
    return 0;
}
```

# const 引用

const 最常见的作用就是在变量作为函数形参的时候加上 const 修饰，起到对形参的保护作用，加了 const 修饰的参数就不会在函数中被修改。

const 如果和引用放在一起会擦出什么火花？

```c++
const int a = 10;
// int &b = a; err
const int &b = a;

int c = 20;
const int &d = c;
// d = 30; err
c = 30;
```

第一组代码想说明的是 const 修饰的常量，如果我想用一直普通的引用指向它是不可以的。假设我们可以用一个普通的 b 做为 a 的引用，那就可以使用 b 去修改 a 所指代的内存，而 a 指向的内存是被 const 保护的，是不允许修改的。不过我们可以使用 const 修饰的引用去指向 a，此时他们的安全级别一样，都不会导致内存被修改的安全问题。

第二组代码想说明的 const 修饰的引用安全级别更高，可以用安全级别高的去引用安全级别低的。这时候造成的现象是 d 被 const 修饰不能修改，而 c 任然可以修改，虽然是同一片内存但是 d 也无法阻止 c 进行修改。

```c++
void printA(const Teacher &teacher) {
    //teacher.age = 33; 
    printf("teacher.age:%d \n", teacher.age);
}
```

上面这段代码则表示 const 修饰的形参是只读的，不允许在函数中进行修改，起到了保护形参的作用。

总结一下：
1. const 引用可以指向安全级别比其低的或者同级的
2. const 引用常在形参传递过程中起保护形参的作用