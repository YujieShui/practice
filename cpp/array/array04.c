#include <stdio.h>

/* 数组指针与二维数组 */
int main()
{

    int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int (*p)[6];
    p = a;
    printf("p = %d, p + 1 = %d\n", p, (p+1));

    return 0;
}