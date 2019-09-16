#include <stdio.h>

int main()
{
    printf("========== 一维数组 ==========\n");

    int a[] = {1, 2, 3, 4};
    // 计算数组大小
    int length_a = sizeof(a)/sizeof(a[0]);

    /* 使用数组下标，遍历一维数组 */
    for (int i = 0; i < length_a; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    /* 使用指针，遍历一维数组 */
    for (int i = 0; i < length_a; i++)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");

    return 0;
}