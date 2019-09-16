
/* 
结构体嵌套二级指针 
1. 一个老师带三个学生，结构体变量版
2. 一个老师带三个学生，指针版

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher
{
    char **stu;
    int age;
};

typedef struct Teacher teacher_t;

int main()
{
    // 1: 一个老师带三个学生，结构体变量版
    teacher_t t;
    t.stu = (char **)malloc(sizeof(char *) * 3);
    char buf[30];
    for (int i = 0; i < 3; i++)
    {
        t.stu[i] = (char *)malloc(30);
        sprintf(buf, "name%d", i);
        strcpy(t.stu[i], buf);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("name: %s\n", t.stu[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (t.stu[i] != NULL)
        {
            free(t.stu[i]);
            t.stu[i] = NULL;
        }
    }

    if (t.stu != NULL)
    {
        free(t.stu);
        t.stu = NULL;
    }

    // 2. 一个老师带三个学生，指针版
    teacher_t *p;
    p = (teacher_t *)malloc(sizeof(teacher_t));
    p->stu = (char **)malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++)
    {
        p->stu[i] = (char *)malloc(sizeof(30));
        strcpy(p->stu[i], "aaaaaa");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", p->stu[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (p->stu[i] != NULL)
        {
            free(p->stu[i]);
            p->stu[i] = NULL;
        }
    }

    if(p->stu != NULL)
    {
        free(p->stu);
        p->stu = NULL;
    }

    if(p != NULL)
    {   
        free(p);
        p = NULL;
    }

    return 0;
}