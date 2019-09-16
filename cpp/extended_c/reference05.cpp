/**
 * C++学习笔记: 指针引用
 **/

#include <iostream>

using namespace std;

struct Teacher
{
    char name[50];
    int age;
};

// 二级指针方式为结构体创建空间
int getTeacher(Teacher **teacher);
// 指针引用为结构体创建空间
int getTeacher02(Teacher *&teahcer);
// 结构体释放空间
void freeTeacher(Teacher *p);

int main()
{

    ///////////////////////////////////
    //       采用二级指针的方式         //
    ///////////////////////////////////

    Teacher *teacher = NULL;
    int result = getTeacher(&teacher);
    if(result < 0)
    {
        perror("初始化失败");
    }

    cout << "name = "<< teacher->name << endl;

    freeTeacher(teacher);

    ///////////////////////////////////
    //       采用指针引用的方式         //
    ///////////////////////////////////

    Teacher *teacher02 = NULL;
    result = getTeacher02(teacher02);

    if(result < 0)
    {
        perror("初始化失败");
    }

    cout << "name = "<< teacher02->name << endl;

    return 0;
}

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

void freeTeacher(Teacher *p)
{
    if(p == NULL)
        return;

    free(p);
}
