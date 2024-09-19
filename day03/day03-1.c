#include <stdio.h>

int add(int num1);

int main(void)
{
    int num1;

    scanf("%d", &num1);

    add(num1);
    int result = add(num1);

    if (result == 0)
    {
        printf("%d == 짝수", result);
    }
    if (result == 1)
    {
        printf("%d == 홀수",result);
    }
    
    
    return 0;
}

int add(int num1)
{
    int result;

    for (int i = 1; i < count; i++)
    {
        /* code */
    }
    
        if (num1 % 2 == 0)
        {
            result = 0;
            return result;
        }
        if (num1 % 3 == 0)
        {
            result = 1;
            return result;
        }
    return 0;
}