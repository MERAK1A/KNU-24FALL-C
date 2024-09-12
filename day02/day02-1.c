#include <stdio.h>

int main(void)
{
    double num1, num2;

    int option;

    printf("원하는 기능을 선택하시오.\n");
    printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
    scanf("%d", &option);

    printf("숫자를 입력하시오.\n");
    scanf("%lf %lf", &num1, &num2);

    if (option == 1)
    {
        printf("%lf + %lf = %lf", num1, num2, num1+num2);
    }   
    else if (option == 2)
    {
        printf("%lf - %lf = %lf", num1, num2, num1 - num2);
    }
    else if (option == 3)
    {
        printf("%lf * %lf = %lf", num1, num2, num1 * num2);
    }
    else if (option == 4)
    {
        printf("%lf / %lf = %lf", num1, num2, num1 / num2);
    }
    else
    {
        printf("잘못 입력하셨습니다.\n");
    }
    

    return 0;
}