/* 结构体数组 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>>

typedef struct Teacher
{
    char name[50];
    int age;
}Teacher;

void show_teacher(Teacher t)
{
    printf("teacher name = %s\n", t.name);
    printf("teacher age = %d\n", t.age);
}

int main()
{
    // 静态结构体数组
    Teacher t1[3] = {"a", 18, "a", 28, "a", 38};
    for(int i = 0; i < 3; i++)
    {
        printf("%s, %d\n", t1[i].name, t1[i].age);
    }


    // 动态结构体数组
    Teacher *p = NULL;
    p = (Teacher *)malloc(3 * sizeof(Teacher));

    char buf[50];
    for(int i = 0; i < 3; i++)
    {
        sprintf(buf, "name%d", i);
        strcpy(p[i].name, buf);
        p[i].age = 20 + i;
    }

    for(int i = 0; i < 3; i++)
    {
        printf("%s, %d\n", p[i].name, p[i].age);
    }
    printf("\n");
    
    if(p != NULL)
    {
        free(p);
        p = NULL;
    }

    return 0;
}