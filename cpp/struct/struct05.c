
/* 将 struct04 中程序封装成函数 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher
{
    char *name;
    int age;
};

typedef struct Teacher teacher_t;

// 为结构体分配内存空间
teacher_t *createTeacher(int n);
// 打印结构体信息
void showTeacher(teacher_t *t, int n);
// 释放接头体内存空间
void freeTeacher(teacher_t *t, int n);

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
    p = createTeacher(1);

    if(p == NULL)
    {
        fprintf(stderr, "createTeacher() error!");
    }
    p->name = (char *)malloc(30);
    strcpy(p->name, "bbbbbbbb");
    p->age = 30;
    printf("name = %s, age = %d\n", p->name, p->age);

    freeTeacher(p, 1);
#endif

#if 0
    teacher_t *q = NULL;
    // 1. 结构体数组，要为其分配内存空间
    q = createTeacher(3);
    if(q == NULL)
    {
        fprintf(stderr, "createTeacher() error!");
    }
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

    showTeacher(q, 3);

    freeTeacher(q, 3);

#endif


    return 0;
}

teacher_t *createTeacher(int n)
{
    teacher_t *t = NULL;
    t = (teacher_t *)malloc(sizeof(teacher_t) * n);
    if(t == NULL)
    {
        return NULL;
    }

    return t;
}

void showTeacher(teacher_t *t, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("name = %s, age = %d\n", t[i].name, t[i].age);
    }
}

void freeTeacher(teacher_t *t, int n)
{
    if(t == NULL)
    {
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(t[i].name != NULL)
        {
            free(t[i].name);
            t[i].name = NULL;
        }
    }
    
    if(t != NULL)
    {
        free(t);
        t = NULL;
    }
}