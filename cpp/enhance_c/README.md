C++ 对 C 语言的增强

# namespace

namespace 就像一幢楼，楼于楼之间的我们用 13 幢、14 幢，楼内都有 103 室、305 室。这样一来，同样是 103 室，我们就能区分出来是 13 幢 103 室，还是 14 幢 103 室。

类比到程序中就是两个不同的类中有同名的函数或者变量，比如两个类都有变量 room，当我们同时使用这两个类并且要用 room 这个变量的时候，怎么才能区分用的是哪个 room 呢？C++ 的解决方案就是使用 namespace。第一个的 namespace 叫 Building12，第二个 namespace 叫 Building13，它们各自有一个 room 变量。使用的时候就和我们找门牌号一样，Building12::room 就表示我们要用 Building12 里面的 room。

## 三种使用名称空间的方法

以打印 hello world 为例，我们要调用 iostream 下的 cout 函数。

```c++
#include <iostream>

int main()
{
    cout << "Hellow World." << endl;
    return 0;
}
```

看代码的意思是我们想要使用 cout 打印一句话，endl 换行，但是这是会报错的，因为没有指定名称空间。

std是c++标准命名空间,c++标准程序库中的所有标识符都被定义在std中,比如标准库中的类iostream、vector等都定义在该命名空间中，有三种方法可以指定 namespace，如下:

```c
// 直接指定标识符，写起来麻烦但是最好的方法，要求这样写
std::cout << "Hellow World." << std::endl;

// 使用 using 关键字
using std::cout;	
using std::endl;	
cout << "Hellow World." << endl;

// 使用 using namespace 名称空间
using namespace std;
cout << "Hellow World." << endl;
```

[代码示例](namespace01.cpp)

## 定义和使用 namespace 

1. 使用 `namespace SpaceName{}` 定义名称空间
2. namespace 可以嵌套

```c++
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
```

# struct 增强

C 语言中将 struct 认为是一种变量，C++ 将 struct 认为是一种新的类型，用代码来解释会更清楚一点。

分别用 C 语言和 C++ 定义下面这样一个结构体: 

```c
struct Student
{
    int age;
    char name[50];
    struct Student *next;
}Student;
```

如果在 C 语言中申明这个结构体变量要使用 `struct Student student`，而在 C++ 中将 Student 认为是新的数据类型可以直接使用 `Student student`， 想在 C 语言中这样会用就要使用 `typedef` 关键字。

# C++ 新增了 bool 类型

C++中的布尔类型。C++在C语言言的基本类型系统之上增加了bool，可取的值只有true和false。我们可以这样使用 bool 比如 `bool b = true`。

# 三目运算符增强

```c++
#include <iostream>

int main()
{
    int a = 10;
    int b = 20;

    (a < b ? a : b) = 30;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}
```

1. C语言返回变量的值 C++语言是返回变量本身，所以 C 语言中三目运算不能作为左值
2. 三目运算符可能返回的值中如果有一个是常量值,则不能作为左值使用

# C++ 中的 const

const 表示一个常量，我们希望常量是固定不能被修改的。

c 语言中 const 的使用可以看之前的这篇文章：[C语言学习笔记-const关键字](https://shuiyujie.com/post/5c7372a9.html)。在 C 语言中 const 修饰的变量任然能通过指针指向常量所在的内存进行修改，就像下面这样：

```c
const int a = 123;
// a = 321; err
int *q = NULL;
q = &a;
*q = 321;
printf("a: %d\n", a);
// c 语言中的 const 是个冒牌货，使用指针任然能够修改
```

在 C++ 中以上这段代码是编译不过的，C++ 禁止 `q = &a`，也就是直接禁止另一个指针指向 const 修饰的变量所在的内存。

# 枚举类型 enum 的增强

c 语言中枚举本质就是整型,枚举变量可以用任意整型赋值。而 c++中枚举变量, 只能用被枚举出来的元素初始化。

```c++
#include <iostream>

enum season 
{
    SPRING,
    SUMMER,
    AUTOON,
    WINTER
};

int main()
{

    enum season season = SPRING;
    // season = 1; // 错误, c 语言中可以
    season = SUMMER;

    std::cout << "season = " << season << std::endl; // 1

    return 0;
}
```