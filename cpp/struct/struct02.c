/* 结构体赋值 */

#include <stdio.h>
#include <string.h>

struct Teacher
{
    char name[50];
    int age;
};

typedef struct Teacher teacher_t;

void show_teacher(teacher_t t);
void copyTeacher(teacher_t *to, teacher_t *from);

int main()
{
    teacher_t t1, t2, t3;

    // 结构体是一种数据类型，分配空间之后才能赋值
    memset(&t1, 0, sizeof(t1));
    strcpy(t1.name, "teacher");
    t1.age = 30;

    show_teacher(t1);

    // 直接赋值
    t2 = t1;
    show_teacher(t2);

    // 作为参数传递到用于拷贝的函数
    copyTeacher(&t3, &t1);
    show_teacher(t3);

    return 0;
}

void copyTeacher(teacher_t *to, teacher_t *from)
{
    *to = *from;
}

void show_teacher(teacher_t t)
{
    printf("teacher name = %s\n", t.name);
    printf("teacher age = %d\n", t.age);
}