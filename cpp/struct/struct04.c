/* 结构体嵌套一级指针 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

之前的结构体是这么定义的，其中 char name[50] 是一个数组变脸
Q: 改成指针变量 char *name 需要注意什么问题？

struct Teacher
{
    char name[50];
    int age;
};
*/

struct Teacher
{
    char *name;
    int age;
};

typedef struct Teacher teacher_t;

int main()
{
   
#if 0
    char *name = NULL;
    strcpy(name, "aaaaaa");
    printf("%s\n", name);
    
    // 报错：name 没有分配内存空间，却要将静态区的资源拷贝给 name
    // 可以采用动态分配空间解决
    // 结构体中使用 char *name 同样会出现这样的问题

#endif

    /*
        示例：
        1. 结构体嵌套一级指针初始化
        2. 结构体嵌套一级指针，并由指针 p 指向这一结构体
        3. 结构体嵌套一级指针，且是一个数组

        关键：
        1. 既需要给结构体分配内存，也需要为结构体中的指针指向的空间分配内存
        2. 释放内存的时候，先释放结构体中指针指向的内存，再释放结构体的指针指向的内存
    */


#if 0
    teacher_t t;
    t.name = (char *)malloc(30);
    strcpy(t.name, "aaaaa");// err
    printf("name: %s\n", t.name);

    if(t.name != NULL)
    {
        free(t.name);
        t.name = NULL;
    }
#endif

#if 0
    teacher_t *p = NULL;
    p = (teacher_t *)malloc(sizeof(teacher_t));
    p->name = (char *)malloc(30);
    strcpy(p->name, "bbbbbbbb");
    p->age = 30;
    printf("name = %s, age = %d\n", p->name, p->age);

    if(p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }

    if(p != NULL)
    {
        free(p);
        p = NULL;
    }
#endif

// #if 0
    teacher_t *q = NULL;
    // 1. 结构体数组，要为其分配内存空间
    q = (teacher_t *)malloc(sizeof(teacher_t) * 3);
    // teacher_t q[3];

    char buf[50];
    for (int i = 0; i < 3; i++)
    {
        sprintf(buf, "name%d", i);
        // 2. 数组指针指向的空间，也要为其分配内存
        q[i].name = (char *)malloc(sizeof(50));
        strcpy(q[i].name, buf);
        q[i].age = 30 + i;
    }

    for(int i = 0; i < 3; i++)
    {
        printf("name = %s, age = %d\n", q[i].name, q[i].age);
    }

    for(int i = 0; i < 3; i++)
    {
        if(q[i].name != NULL)
        {
            free(q[i].name);
            q[i].name = NULL;
        }
    }
    
    if(q != NULL)
    {
        free(q);
        q = NULL;
    }

// #endif


    return 0;
}