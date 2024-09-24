#include <stdio.h>


int main(void)
{
    int a = 100, b = 100;

    int* pnum1 = &a;
    *pnum1 += 30;

    printf("%d\n", a);

    int* pnum2= &b;
    *pnum2 -= 30;


    printf("%d", b);


    return 0;
}