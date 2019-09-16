#include "head.h"

int main(void)
{
    int a = 2;
    int b = 6;

    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d x %d = %d\n", a, b, mul(a, b));

    return 0;
}
