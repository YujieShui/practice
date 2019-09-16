# inline 内联函数

```c++
// 主函数循环调用 my_min() 函数
for(int i = 0; i < 1000; i++)
{
    min = my_min(a, b);
    cout << "min = " << min << endl;
}

// 比较两个值的大小
int my_min(int a, int b)
{
    return (a < b ? a : b);
}
```
当主函数调用函数的时候会有频繁的入栈、出栈操作。如果想减少这部分时间开销，在 C 语言中我们使用宏定义，在 C++ 中使用内联函数。

```c
#define MY_MAX(a, b) ((a) < (b) ? (a) : (b))

for(int i = 0; i < 1000; i++)
{
    min = MY_MAX(a, b);
    cout << "min = " << min << endl;
}
```

使用 C 语言中的宏定义我们可以让被调用的函数由预编译器展开，不会再有出栈入栈的过程，然而这样做存在一个问题。由于宏定义在编译的时候就展开，如果使用 `MY_MAX(a++, b++)` 的方式调用就会被展开成 `MY_MAX(a++, b++) ((a++) < (b++) ? (a++) : (b++))`。

C++ 采用 inline 关键字来申明一个内联函数。内联函数是一种特殊的函数,具有普通函数的特征，但是**C++编译器直接将函数体插入在函数调用的地方**。

```c++
// inline 关键字修饰的内联函数
inline int my_max(int a, int b)
{
    return (a > b ? a : b);
}
```

最后是内联函数使用的注意事项:

1. 不能存在任何形式的循环语句
2. 不能存在过多的条件判断语句
3. 不能对函数进行取址操作
4. 函数内联声明必须在调用语句之前 

# 默认参数与占位符

默认参数与占位符用于 C++ 定义函数的时候，相对于 C 语言有有更多的特性。

```c++
#include <iostream>

int function_name(int a, int b = 10)
{
    std::cout << "a = " << a << " b = " << b << std::endl;
}

int main()
{
    int a = 20;
    int b = 30;

    function_name(a, b);
    function_name(a);

    return 0;
}
```

在函数 `int function_name(int a, int b = 10)` 中，我们在函数定义的过程中给 b 一个默认值，当函数调用时如果未传入 b 就会使用默认的 b 的值。

关于默认参数有这样几条规则

1. 可以有多个默认值
2. 默认值必须从后面写起 `typename function_name(int a, int b, ... int x =10, int y =20)`
3. 一旦在一个函数调用中开始使用默认参数值,那么这个参数后的所有参数都必须使用默认参数值 

占位符就感觉比较鸡肋了,我们使用一个没有名字的只有类型的形参作为占位符，但因为它没有名字，在函数中也没有办法使用。

```c++
// 占位符
int	func(int a,	int b, int)	
{	
    return (a + b);
}

// 占位符并赋予默认值
int	func(int a,	int b, int = 10)	
{	
    return (a + b);
}
```

# 函数重载

```c
int funtion_name(int a, int b);
int funtion_name(int a);
```

以上这段代码在 C 语言中是会报错的，因为 C 语言禁止函数同名，而在 C++ 中这样是允许的，被称为函数重载。

一个函数包含这样三个部分

1. 返回值类型
2. 方法名名称
3. 参数列表（参数类型，参数个数）

```c++
void func(int a);//ok
void func(char a);//ok, 参数个数相同，参数类型不同	
void func(int a, int b);//ok 参数个数不同
char func(int a);//error,与第一一个函数有冲突	
```