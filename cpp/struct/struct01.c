#include <stdio.h>
#include <string.h>

/*
* 1. 结构体的类型定义
* 2. 结构体的变量定义
* 3. 结构体变量的初始化
* 4. typedf 改变类型名
* 5. 点运算符和指针法操作结构体
* 6. 结构体也是一种数据类型: 复合类型，自定义类型
*/


struct Teacher
{
    char name[50];
    int age;
}t1, t2; // 初始化结构体变量1: 定义类型的同时定义变量

struct Student
{
    char name[50];
    int age;
}s1 = {"Mike", 15}; // 初始化结构体变量2

struct
{
    char name[50];
    int age;
}dog = {"Luck", 3}; // 初始化结构体变量3

int main()
{
    // 初始化结构体变量4，申明变量并直接初始化
    struct Teacher t3 = {"Mary", 21};

    printf("teacher name: %s\n", t3.name);
    printf("teacher age: %d\n", t3.age);

    // 初始化结构体变量5，利用指针
    struct Teacher t4;
    struct Teacher *pTeacher = NULL;
    pTeacher = &t4;

    strcpy(pTeacher->name, "John");
    pTeacher->age = 30;

    printf("teacher name: %s\n", t4.name);
    printf("teacher age: %d\n", t4.age);

    return 0;
}