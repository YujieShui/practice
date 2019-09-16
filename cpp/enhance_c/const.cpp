#include <iostream>
#include "stdio.h"

int main()
{
    const int a = 123;
    // a = 321; err
    int *q = NULL;

    // q = &a; 
    // a value of type "const int *" cannot be assigned to an entity of type "int *"
    
    
    
    // *q = 321;
    printf("a: %d\n", a);
    // c 语言中的 const 是个冒牌货，使用指针任然能够修改
    


    return 0;
}